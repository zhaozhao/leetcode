#include "catch.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

bool isValidBST(TreeNode* node, TreeNode* min_node, TreeNode* max_node) {
    if (node == NULL) return true;
    if (min_node != NULL && node->val <= min_node->val) return false;
    if (max_node != NULL && node->val >= max_node->val) return false;
    return isValidBST(node->left, min_node, node) && isValidBST(node->right, node, max_node);
}

bool isValidBST(TreeNode *root) {
    return isValidBST(root, NULL, NULL);
}


TEST_CASE("validate_binary_search_tree") {
    TreeNode singal(0);
    REQUIRE( isValidBST(&singal) == true);
}