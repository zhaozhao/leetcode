#include "catch.hpp"
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

TEST_CASE("maxmum depth of binary tree") {
    TreeNode root(0);
    TreeNode left(0);
    TreeNode left_left(0);
    root.left = &left;
    left.left = &left_left;
    REQUIRE(maxDepth(&root) == 3);
}