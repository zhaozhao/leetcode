#include "catch.hpp"
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    deque<TreeNode *> fifo;
    fifo.push_back(root);
    fifo.push_back(NULL);
    vector<int> current;
    while (!fifo.empty()) {
        TreeNode *node = fifo.front();
        fifo.pop_front();
        if (node != NULL) {
            current.push_back(node->val);
            if (node->left) fifo.push_back(node->left);
            if (node->right) fifo.push_back(node->right);
        }
        else {
            result.push_back(current);
            current.resize(0);
            if (!fifo.empty()) {
                fifo.push_back(NULL);
            }
        }
    }
    return result;
}

TEST_CASE("binary tree level order traversal") {
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(2);
    root.left = &left;
    root.right = &right;
    vector<vector<int>> exp = {{0}, {1,2}};
    REQUIRE( levelOrder(&root) == exp);
}