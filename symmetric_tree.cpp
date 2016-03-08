#include "catch.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL)
        return true;
    return isSymmetric(root->left, root->right);

}


TEST_CASE("symmetric tree") {
    REQUIRE(isSymmetric(NULL) == true);
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(1);
    root.left = &left;
    root.right = &right;
    REQUIRE(isSymmetric(&root) == true);
}
