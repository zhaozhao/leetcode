#include "catch.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    if (root->val == sum && root->left == NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

TEST_CASE("path sum") {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode left_left(3);
    root.left = &left;
    left.left = &left_left;
    REQUIRE(hasPathSum(&root, 6));
    REQUIRE(!hasPathSum(&root, 1));
    REQUIRE(!hasPathSum(&root, 7));
}