// Function: revoked_serial_tree_RB_REMOVE_COLOR @ 0x9f0a0
struct rb_node {
    unsigned char data[16];
    struct rb_node *left;
    struct rb_node *right;
    struct rb_node *parent;
    int color;
};

struct rb_tree {
    struct rb_node *root;
};

enum rb_color {
    RB_BLACK,
    RB_RED
};

void
revoked_serial_tree_RB_REMOVE_COLOR(struct rb_tree *tree, struct rb_node *parent,
    struct rb_node *node)
{
    struct rb_node *sibling;
    struct rb_node *pivot;

    while ((node == 0 || node->color == RB_BLACK) && node != tree->root) {
        if (node == parent->left) {
            sibling = parent->right;
            if (sibling->color == RB_RED) {
                sibling->color = RB_BLACK;
                parent->color = RB_RED;

                pivot = parent->right;
                parent->right = pivot->left;
                if (pivot->left != 0)
                    pivot->left->parent = parent;
                pivot->parent = parent->parent;
                if (parent->parent == 0)
                    tree->root = pivot;
                else if (parent == parent->parent->left)
                    parent->parent->left = pivot;
                else
                    parent->parent->right = pivot;
                pivot->left = parent;
                parent->parent = pivot;

                sibling = parent->right;
            }
            if ((sibling->left == 0 ||
                sibling->left->color == RB_BLACK) &&
                (sibling->right == 0 ||
                sibling->right->color == RB_BLACK)) {
                sibling->color = RB_RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->right == 0 ||
                    sibling->right->color == RB_BLACK) {
                    sibling->left->color = RB_BLACK;
                    sibling->color = RB_RED;

                    pivot = sibling->left;
                    sibling->left = pivot->right;
                    if (pivot->right != 0)
                        pivot->right->parent = sibling;
                    pivot->parent = sibling->parent;
                    if (sibling->parent == 0)
                        tree->root = pivot;
                    else if (sibling == sibling->parent->left)
                        sibling->parent->left = pivot;
                    else
                        sibling->parent->right = pivot;
                    pivot->right = sibling;
                    sibling->parent = pivot;

                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = RB_BLACK;
                if (sibling->right != 0)
                    sibling->right->color = RB_BLACK;

                pivot = parent->right;
                parent->right = pivot->left;
                if (pivot->left != 0)
                    pivot->left->parent = parent;
                pivot->parent = parent->parent;
                if (parent->parent == 0)
                    tree->root = pivot;
                else if (parent == parent->parent->left)
                    parent->parent->left = pivot;
                else
                    parent->parent->right = pivot;
                pivot->left = parent;
                parent->parent = pivot;

                node = tree->root;
                break;
            }
        } else {
            sibling = parent->left;
            if (sibling->color == RB_RED) {
                sibling->color = RB_BLACK;
                parent->color = RB_RED;

                pivot = parent->left;
                parent->left = pivot->right;
                if (pivot->right != 0)
                    pivot->right->parent = parent;
                pivot->parent = parent->parent;
                if (parent->parent == 0)
                    tree->root = pivot;
                else if (parent == parent->parent->left)
                    parent->parent->left = pivot;
                else
                    parent->parent->right = pivot;
                pivot->right = parent;
                parent->parent = pivot;

                sibling = parent->left;
            }
            if ((sibling->left == 0 ||
                sibling->left->color == RB_BLACK) &&
                (sibling->right == 0 ||
                sibling->right->color == RB_BLACK)) {
                sibling->color = RB_RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->left == 0 ||
                    sibling->left->color == RB_BLACK) {
                    sibling->right->color = RB_BLACK;
                    sibling->color = RB_RED;

                    pivot = sibling->right;
                    sibling->right = pivot->left;
                    if (pivot->left != 0)
                        pivot->left->parent = sibling;
                    pivot->parent = sibling->parent;
                    if (sibling->parent == 0)
                        tree->root = pivot;
                    else if (sibling == sibling->parent->left)
                        sibling->parent->left = pivot;
                    else
                        sibling->parent->right = pivot;
                    pivot->left = sibling;
                    sibling->parent = pivot;

                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = RB_BLACK;
                if (sibling->left != 0)
                    sibling->left->color = RB_BLACK;

                pivot = parent->left;
                parent->left = pivot->right;
                if (pivot->right != 0)
                    pivot->right->parent = parent;
                pivot->parent = parent->parent;
                if (parent->parent == 0)
                    tree->root = pivot;
                else if (parent == parent->parent->left)
                    parent->parent->left = pivot;
                else
                    parent->parent->right = pivot;
                pivot->right = parent;
                parent->parent = pivot;

                node = tree->root;
                break;
            }
        }
    }
    if (node != 0)
        node->color = RB_BLACK;
}


