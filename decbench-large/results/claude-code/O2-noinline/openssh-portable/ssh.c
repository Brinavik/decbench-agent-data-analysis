// Function: revoked_serial_tree_RB_REMOVE_COLOR @ 0x9f0a0
/* Red-black tree delete rebalancing (CLRS RB-DELETE-FIXUP).
 * The node "x" being fixed up may be a (null) leaf, so its parent is
 * passed explicitly rather than read from x->parent. */

enum rb_color { RB_BLACK = 0, RB_RED = 1 };

struct rb_node {
    void          *key;      /* 0x00 */
    void          *value;    /* 0x08 */
    struct rb_node *left;    /* 0x10 */
    struct rb_node *right;   /* 0x18 */
    struct rb_node *parent;  /* 0x20 */
    int            color;    /* 0x28 */
};

void revoked_serial_tree_RB_REMOVE_COLOR(struct rb_node **root, struct rb_node *parent, struct rb_node *x)
{
    while (x != *root && (x == 0 || x->color == RB_BLACK)) {
        struct rb_node *w, *y;

        if (x == parent->left) {
            w = parent->right;

            if (w->color == RB_RED) {
                /* case 1 */
                w->color = RB_BLACK;
                parent->color = RB_RED;
                /* left-rotate(parent) */
                y = w;
                parent->right = y->left;
                if (y->left)
                    y->left->parent = parent;
                y->parent = parent->parent;
                if (parent->parent == 0)
                    *root = y;
                else if (parent == parent->parent->left)
                    parent->parent->left = y;
                else
                    parent->parent->right = y;
                y->left = parent;
                parent->parent = y;
                w = parent->right;
            }

            if ((w->left == 0 || w->left->color == RB_BLACK) &&
                (w->right == 0 || w->right->color == RB_BLACK)) {
                /* case 2 */
                w->color = RB_RED;
                x = parent;
                parent = parent->parent;
            } else {
                if (w->right == 0 || w->right->color == RB_BLACK) {
                    /* case 3 */
                    w->left->color = RB_BLACK;
                    w->color = RB_RED;
                    /* right-rotate(w) */
                    y = w->left;
                    w->left = y->right;
                    if (y->right)
                        y->right->parent = w;
                    y->parent = w->parent;
                    if (w->parent == 0)
                        *root = y;
                    else if (w->parent->left == w)
                        w->parent->left = y;
                    else
                        w->parent->right = y;
                    y->right = w;
                    w->parent = y;
                    w = parent->right;
                }
                /* case 4 */
                w->color = parent->color;
                parent->color = RB_BLACK;
                if (w->right)
                    w->right->color = RB_BLACK;
                /* left-rotate(parent) */
                y = parent->right;
                parent->right = y->left;
                if (y->left)
                    y->left->parent = parent;
                y->parent = parent->parent;
                if (parent->parent == 0)
                    *root = y;
                else if (parent == parent->parent->left)
                    parent->parent->left = y;
                else
                    parent->parent->right = y;
                y->left = parent;
                parent->parent = y;
                x = *root;
            }
        } else {
            w = parent->left;

            if (w->color == RB_RED) {
                /* case 1 (mirror) */
                w->color = RB_BLACK;
                parent->color = RB_RED;
                /* right-rotate(parent) */
                y = w;
                parent->left = y->right;
                if (y->right)
                    y->right->parent = parent;
                y->parent = parent->parent;
                if (parent->parent == 0)
                    *root = y;
                else if (parent->parent->left == parent)
                    parent->parent->left = y;
                else
                    parent->parent->right = y;
                y->right = parent;
                parent->parent = y;
                w = parent->left;
            }

            if ((w->left == 0 || w->left->color == RB_BLACK) &&
                (w->right == 0 || w->right->color == RB_BLACK)) {
                /* case 2 (mirror) */
                w->color = RB_RED;
                x = parent;
                parent = parent->parent;
            } else {
                if (w->left == 0 || w->left->color == RB_BLACK) {
                    /* case 3 (mirror) */
                    w->right->color = RB_BLACK;
                    w->color = RB_RED;
                    /* left-rotate(w) */
                    y = w->right;
                    w->right = y->left;
                    if (y->left)
                        y->left->parent = w;
                    y->parent = w->parent;
                    if (w->parent == 0)
                        *root = y;
                    else if (w->parent->left == w)
                        w->parent->left = y;
                    else
                        w->parent->right = y;
                    y->left = w;
                    w->parent = y;
                    w = parent->left;
                }
                /* case 4 (mirror) */
                w->color = parent->color;
                parent->color = RB_BLACK;
                if (w->left)
                    w->left->color = RB_BLACK;
                /* right-rotate(parent) */
                y = parent->left;
                parent->left = y->right;
                if (y->right)
                    y->right->parent = parent;
                y->parent = parent->parent;
                if (parent->parent == 0)
                    *root = y;
                else if (parent->parent->left == parent)
                    parent->parent->left = y;
                else
                    parent->parent->right = y;
                y->right = parent;
                parent->parent = y;
                x = *root;
            }
        }
    }

    if (x)
        x->color = RB_BLACK;
}


