import json
import unittest
from pathlib import Path

from analyze_large_error_patterns import canonical_function_signature, target_signature
from download_large_scan_inputs import extract_function_definition, looks_like_definition


ROOT = Path(__file__).resolve().parent
DATASET = ROOT / "decbench-large"


class DefinitionParserTests(unittest.TestCase):
    def test_ansi_definition(self):
        self.assertTrue(looks_like_definition("static int f(int x) { return x; }", "f"))

    def test_rejects_prototype_and_call(self):
        self.assertFalse(looks_like_definition("int f(int x);\nvoid g(void) { f(1); }", "f"))

    def test_kr_definition(self):
        code = """local void inflate_fast(strm, start)
        z_streamp strm;
        unsigned start;
        {
        }
        """
        self.assertTrue(looks_like_definition(code, "inflate_fast"))

    def test_zexport_kr_definition(self):
        code = """int ZEXPORT inflateTable(type, lens, codes, table, bits, mask)
        int type;
        unsigned short FAR *lens;
        unsigned codes;
        void *table;
        unsigned *bits;
        unsigned mask;
        {
        }
        """
        self.assertTrue(looks_like_definition(code, "inflateTable"))

    def test_of_double_parenthesis_definition(self):
        code = "int ZEXPORT inflate OF((z_streamp strm, int flush)) { return flush; }"
        self.assertTrue(looks_like_definition(code, "inflate"))

        extracted = extract_function_definition(code, "inflate")
        self.assertIsNotNone(extracted)
        self.assertEqual(
            canonical_function_signature(extracted, "inflate"),
            ("int", ("z_streamp", "int")),
        )

    def test_of_double_parenthesis_prototype(self):
        code = "ZEXTERN int ZEXPORT inflate OF((z_streamp strm, int flush));"
        self.assertFalse(looks_like_definition(code, "inflate"))

    def test_kr_signature_and_local_modifier(self):
        code = """local void inflate_fast(strm, start)
        z_streamp strm;
        unsigned start;
        {
        }
        """
        self.assertEqual(
            canonical_function_signature(code, "inflate_fast"),
            ("void", ("z_streamp", "unsigned")),
        )

    def test_dangling_comment_prefix_is_not_return_type(self):
        code = "comment tail */\nvoid inflate_fast(z_streamp strm, unsigned start) {}"
        self.assertEqual(target_signature(code, "inflate_fast"), ("void", "z_streamp strm, unsigned start"))


class LocalCorpusRegressionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        inventory_path = DATASET / "large_download_inventory.json"
        if not inventory_path.is_file():
            raise unittest.SkipTest("local DecBench inventory is unavailable")
        cls.inventory = json.loads(inventory_path.read_text(encoding="utf-8"))

    def test_previously_verified_sources_still_match(self):
        checked = 0
        for row in self.inventory:
            for rel in row.get("source_paths", []):
                path = DATASET / rel
                if path.is_file():
                    self.assertTrue(
                        looks_like_definition(path.read_text(encoding="utf-8", errors="replace"), row["function"]),
                        f"regression: {row['project']}/{row['binary']}/{row['function']} in {rel}",
                    )
                    checked += 1
        self.assertGreaterEqual(checked, 47)

    def test_four_zlib_failures(self):
        expected = {
            "deflate_slow": "sources/zlib/deflate.c",
            "inflate_table": "sources/zlib/inftrees.c",
            "main": "sources/zlib/minigzip.c",
            "inflate_fast": "sources/zlib/inffast.c",
        }
        for function, rel in expected.items():
            path = DATASET / rel
            self.assertTrue(path.is_file(), rel)
            self.assertTrue(
                looks_like_definition(path.read_text(encoding="utf-8", errors="replace"), function),
                f"zlib parser failure: {function} in {rel}",
            )


if __name__ == "__main__":
    unittest.main()
