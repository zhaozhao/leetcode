#include "catch.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TEST_CASE("same tree") {
    SECTION("null") {
        TreeNode *p = NULL;
        TreeNode *q = NULL;
        REQUIRE(isSameTree(p, q));
    }
    SECTION("one is null") {
        TreeNode *p = new TreeNode(0);
        TreeNode *q = NULL;
        REQUIRE(isSameTree(p, q) == false);
    }
    SECTION("one same node") {
        TreeNode *p = new TreeNode(0);
        TreeNode *q = new TreeNode(0);
        REQUIRE(isSameTree(p, q));
    }
}