//
// Created by Cloud on 2015-08-10.
//
#include <vector>
using namespace std;

#ifndef TREE_SOLUTION5_1_H
#define TREE_SOLUTION5_1_H

struct TreeNode {

    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) { }
};

class Solution5_1 {
public:
    vector<int> preOrderTraversal1(TreeNode *root) ;
    vector<int> preorderTraversal(TreeNode* root) ;
    vector<int> inorderTraversal(TreeNode* root);
    vector<int> inOrderTraversal1(TreeNode *root);
    vector<int> postOrderTraversal(TreeNode *root);
    void preOrderRecurive(TreeNode *root, vector<int> &result);
    void levelOrderRecurive(TreeNode *root, int level, vector<vector<int>> &result);
    vector<vector<int>> levelOrder(TreeNode *root);
    vector<vector<int>> levelOrderQueue(TreeNode *root);
    vector<vector<int>> levelOrderReverse(TreeNode *root);
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);
    bool isSymmetric(TreeNode *root);
    bool isBalanced(TreeNode *root);

private:
    bool isSymmetric(TreeNode *left, TreeNode *right);

};
#endif //TREE_SOLUTION5_1_H
