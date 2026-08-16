
const char *ssh_err(int n);

const char *
ssh_err(int n)
{
 switch (n) {
 case 0:
  return "success";
 case -1:
  return "unexpected internal error";
 case -2:
  return "memory allocation failed";
 case -3:
  return "incomplete message";
 case -4:
  return "invalid format";
 case -5:
  return "bignum is negative";
 case -6:
  return "string is too large";
 case -7:
  return "bignum is too large";
 case -8:
  return "elliptic curve point is too large";
 case -9:
  return "insufficient buffer space";
 case -10:
  return "invalid argument";
 case -11:
  return "key bits do not match";
 case -12:
  return "invalid elliptic curve";
 case -13:
  return "key type does not match";
 case -14:
  return "unknown or unsupported key type";
 case -15:
  return "elliptic curve does not match";
 case -16:
  return "plain key provided where certificate required";
 case -17:
  return "key lacks certificate data";
 case -18:
  return "unknown/unsupported certificate type";
 case -19:
  return "invalid certificate signing key";
 case -20:
  return "invalid elliptic curve value";
 case -21:
  return "incorrect signature";
 case -22:
  return "error in libcrypto";
 case -23:
  return "unexpected bytes remain after decoding";
 case -24:
  return strerror(
                 (*__errno_location ())
                      );
 case -25:
  return "invalid certificate";
 case -26:
  return "communication with agent failed";
 case -27:
  return "agent refused operation";
 case -28:
  return "DH GEX group out of range";
 case -29:
  return "disconnected";
 case -30:
  return "message authentication code incorrect";
 case -31:
  return "no matching cipher found";
 case -32:
  return "no matching MAC found";
 case -33:
  return "no matching compression method found";
 case -34:
  return "no matching key exchange method found";
 case -35:
  return "no matching host key type found";
 case -37:
  return "protocol version mismatch";
 case -38:
  return "could not read protocol version";
 case -36:
  return "could not load host key";
 case -39:
  return "rekeying not supported by peer";
 case -40:
  return "passphrase is too short (minimum five characters)";
 case -41:
  return "file changed while reading";
 case -42:
  return "key encrypted using unsupported cipher";
 case -43:
  return "incorrect passphrase supplied to decrypt private key";
 case -44:
  return "bad permissions";
 case -45:
  return "certificate does not match key";
 case -46:
  return "key not found";
 case -47:
  return "agent not present";
 case -48:
  return "agent contains no identities";
 case -49:
  return "internal error: buffer is read-only";
 case -50:
  return "KRL file has invalid magic number";
 case -51:
  return "Key is revoked";
 case -52:
  return "Connection closed";
 case -53:
  return "Connection timed out";
 case -54:
  return "Connection corrupted";
 case -55:
  return "Protocol error";
 case -56:
  return "Invalid key length";
 case -57:
  return "number is too large";
 case -58:
  return "signature algorithm not supported";
 case -59:
  return "requested feature not supported";
 case -60:
  return "device not found";
 default:
  return "unknown error";
 }
}
