//
// Created by Cloud on 2015-08-10.
//
#include <vector>
#include <climits>
using namespace std;

#ifndef TREE_SOLUTION5_1_H
#define TREE_SOLUTION5_1_H
typedef vector<int>::iterator Iterator;
struct TreeNode {

    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) { }
};

class Solution5_1 {
public:
    // Binary Tree Preorder Traversal
    vector<int> preOrderTraversal1(TreeNode *root) ;
    // Binary Tree Preorder Traversal
    vector<int> preorderTraversal(TreeNode* root) ;
    // Binary Tree Inorder Traversal
    vector<int> inorderTraversal(TreeNode* root);
    // Binary Tree Inorder Traversal
    vector<int> inOrderTraversal1(TreeNode *root);
    // Binary Tree Postorder Traversal
    vector<int> postOrderTraversal(TreeNode *root);
    // Binary Tree Preorder Traversal
    void preOrderRecurive(TreeNode *root, vector<int> &result);
    void levelOrderRecurive(TreeNode *root, int level, vector<vector<int>> &result);
    // Binary Tree Level Order Traversal
    vector<vector<int>> levelOrder(TreeNode *root);
    // Binary Tree Level Order Traversal
    vector<vector<int>> levelOrderQueue(TreeNode *root);
    // Binary Tree Level Order Traversal II
    vector<vector<int>> levelOrderReverse(TreeNode *root);
    // Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);
    // Symmetric Tree
    bool isSymmetric(TreeNode *root);
    // Balanced Binary Tree
    bool isBalanced(TreeNode *root);
    // Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode *buildTreePreIn(vector<int> &preorder, vector<int> &inorder);
    // Construct Binary Tree from Inorder and Postorder Traversal
    TreeNode *buildTreeInPost(vector<int> &inorder, vector<int> &postorder);
    // Unique Binary Search Trees II
    vector<TreeNode*> generateTree(int n);
    // Minimum Depth of Binary Tree
    int minDepth(TreeNode* root);

private:
    int minDepth(TreeNode *root, bool hasBrother);
};
#endif //TREE_SOLUTION5_1_H
