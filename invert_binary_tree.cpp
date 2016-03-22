#include "catch.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) return root;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

TEST_CASE("invert binary tree") {
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(2);
    root.left = &left;
    root.right = &right;
    auto reverted = invertTree(&root);
    REQUIRE(reverted->left->val == 2);
    REQUIRE(reverted->right->val == 1);
}
