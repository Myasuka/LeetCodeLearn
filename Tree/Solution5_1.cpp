//
// Created by Cloud on 2015-08-10.
//

#include "Solution5_1.h"
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


vector<int>   Solution5_1::preOrderTraversal1(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root;
    if (p != nullptr) {
        s.push(p);
    }
    while (!s.empty()) {
        p = s.top();
        s.pop();
        result.push_back(p->value);
        if (p->right != nullptr) s.push(p->right);
        if (p->left != nullptr) s.push(p->left);
    }
    return result;
}

vector<int>  Solution5_1::preorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p != nullptr || !s.empty()) {
        if (p != nullptr) {
            result.push_back(p->value);
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return result;
}

vector<int>  Solution5_1::inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p != nullptr || !s.empty()) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            result.push_back(p->value);
            s.pop();
            p = p->right;
        }
    }
    return result;
}

vector<int>  Solution5_1::inOrderTraversal1(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            result.push_back(p->value);
            s.pop();
            p = p->right;
        }
    }
    return result;
}

vector<int>  Solution5_1::postOrderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root;
    TreeNode *q;
    if (p != nullptr) {
        s.push(p);
    }
    while (!s.empty() || p != nullptr) {
        if (p->left != nullptr && p->left != q && p->right != q) {
            s.push(p->left);
            p = p->left;
        } else if (p->right != nullptr && p->right != q) {
            s.push(p->right);
            p = p->right;
        } else {
            result.push_back(p->value);
            q = p;
            s.pop();
            p = s.empty() ? nullptr : s.top();
        }
    }
    return result;
}

void  Solution5_1::preOrderRecurive(TreeNode *root, vector<int> &result) {
    TreeNode *p = root;
    if (p != NULL) {
        result.push_back(p->value);
        preOrderRecurive(p->left, result);
        preOrderRecurive(p->right, result);
    }
    return;
}

void  Solution5_1::levelOrderRecurive(TreeNode *root, int level, vector<vector<int>> &result) {
    TreeNode *p = root;
    if (p == nullptr)
        return;
    if (level > result.size()) {
        result.push_back(vector<int>());
    }
    result[level - 1].push_back(p->value);
    if (p->left != nullptr) {
        levelOrderRecurive(p->left, level + 1, result);
    }
    if (p->right != nullptr) {
        levelOrderRecurive(p->right, level + 1, result);
    }
}

struct NodeLevel{
    TreeNode *node;
    int level;

public:
    NodeLevel(TreeNode *n, int l): node(n), level(l) {};
};


// Binary Tree Level Order Traversal, Accepted
vector<vector<int>> Solution5_1::levelOrder(TreeNode *root) {
    int level = 1;
    vector<vector<int>> result;
    TreeNode *p = root;
    stack<NodeLevel *> s;
    while (! s.empty() || p != nullptr){
        if (p != nullptr){
            s.push(new NodeLevel(p, level));
            if ( level > result.size()){
                result.push_back(vector<int>());
            }
            result[level - 1].push_back(p->value);
            p = p->left;
            ++ level;
        }else {
            p = s.top()->node;
            level = s.top()->level;
            s.pop();
            p = p->right;
            ++ level;
        }
    }
    return result;
}

// Binary Tree Level Order Traversal, Accepted
vector<vector<int>> Solution5_1::levelOrderQueue(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    queue<int> qlevel;
    int level = 1;
    TreeNode *p = root;
    if (p != nullptr) {
        q.push(p);
        qlevel.push(level);
    }else return result;
    while(!q.empty()){
        p = q.front();
        level = qlevel.front();
        if (level > result.size()) {
            result.push_back(vector<int>());
        }
        result[level - 1].push_back(p->value);
        if (p->left != nullptr) {
            q.push(p->left);
            qlevel.push(level + 1);
        }
        if (p->right != nullptr) {
            q.push(p->right);
            qlevel.push(level + 1);
        }
        q.pop();
        qlevel.pop();
    }
    return result;
}

// Binary Tree Level Order Traversal II, Accepted
vector<vector<int>> Solution5_1::levelOrderReverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    queue<int> qlevel;
    TreeNode *p = root;
    int level = 1;
    if (p != nullptr){
        q.push(p);
        qlevel.push(level);
    }else return result;
    while (! q.empty()){
        p = q.front();
        level = qlevel.front();
        if (level > result.size()){
            result.push_back(vector<int>());
        }
        result[level -1].push_back(p->value);
        if (p->left != nullptr){
            q.push(p->left);
            qlevel.push(level + 1);
        }
        if (p->right != nullptr){
            q.push(p->right);
            qlevel.push(level + 1);
        }
        q.pop();
        qlevel.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Binary Tree Zigzag Level Order Traversal, Accepted
vector<vector<int>> Solution5_1::zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    stack<TreeNode *> s;
    stack<int> sLevel;
    TreeNode *p = root;
    int level = 1;
    if (p != nullptr) {
        s.push(p);
        sLevel.push(level);
    }
    while(! s.empty()){
        p = s.top();
        level = sLevel.top();
        s.pop();
        sLevel.pop();
        if(level > result.size()){
            result.push_back(vector<int>());
        }
        result[level - 1].push_back(p->value);
        if(p->left != nullptr){
            s.push(p->left);
            sLevel.push(level + 1);
        }
        if (p->right != nullptr){
            s.push(p->right);
            sLevel.push(level + 1);
        }
    }
    for (int i=2; i< result.size(); i += 2){
        reverse(result[i].begin(), result[i].end());
    }
    return result;
}

bool iSymmetric(TreeNode *left, TreeNode *right){
    if (left == nullptr && right == nullptr) return true;
    if ((left!=nullptr)^(right!=nullptr)) return false;
    return (left->value == right->value) && iSymmetric(left->left, right->right)
           && iSymmetric(left->right, right->left);
}

bool Solution5_1::isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return iSymmetric(root->left, root->right);
}

int degree(TreeNode *p){
    if (p == nullptr) return 0;
    if ((p->left == nullptr) && (p->right == nullptr)) return 1;
    int le = degree(p->left);
    int ri = degree(p->right);
    if (le < 0 || ri < 0 || abs(le - ri) > 1) return -1;
    return max(le, ri) + 1;
}

bool Solution5_1::isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    return degree(root) >= 0;
}


// Construct Binary Tree from Preorder and Inorder Traversal, accepted
TreeNode *buildTree1(Iterator pre_first, Iterator pre_last,
                    Iterator in_first, Iterator in_last){
    if (pre_first == pre_last) return nullptr;
    TreeNode *root;
    if ((pre_last - pre_first) == 1){
        root = new TreeNode(*pre_first);
        return root;
    }
    root = new TreeNode(*pre_first);
    auto it = find(in_first, in_last, root->value);
    int pos = distance(in_first, it);
    root->left = buildTree1(pre_first + 1, pre_first + pos + 1, in_first, in_first + pos);
    root->right = buildTree1(pre_first + pos + 1, pre_last, in_first + pos + 1, in_last);
    return root;
}

TreeNode *buildTree2(Iterator in_first, Iterator in_last, Iterator post_first, Iterator post_last){
    if (in_first == in_last) return nullptr;
    TreeNode *root;
    if (in_last - in_first == 1){
        root = new TreeNode(*in_first);
        return root;
    }
    root = new TreeNode(*(post_last - 1));
    auto it = find(in_first, in_last, *(post_last - 1));
    int pos = distance(in_first, it);
    root->left = buildTree2(in_first, in_first + pos , post_first, post_first + pos);
    root->right = buildTree2(in_first + pos + 1, in_last, post_first + pos, post_last - 1);
    return root;
}

TreeNode *Solution5_1::buildTreePreIn(vector<int> &preorder, vector<int> &inorder) {
    return buildTree1(begin(preorder), end(preorder), begin(inorder), end(inorder));
}


TreeNode *Solution5_1::buildTreeInPost(vector<int> &inorder, vector<int> &postorder) {
    return buildTree2(begin(inorder), end(inorder), begin(postorder), end(postorder));
}

vector<TreeNode*> generate(int start, int end){
    vector<TreeNode*> subTrees;
    if(start > end) {
        subTrees.push_back(nullptr);
        return subTrees;
    }
    for(int i=start; i<=end; i++){
        vector<TreeNode*> leftSubs = generate(start, i-1);
        vector<TreeNode*> rightSubs = generate(i+1, end);
        for(auto l: leftSubs){
            for(auto r: rightSubs){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                subTrees.push_back(root);
            }
        }
    }
    return subTrees;
}
vector<TreeNode *> Solution5_1::generateTree(int n) {
    return generate(1, n);
}

int minDepth(TreeNode *root, bool hasBrother) {
    if(root == nullptr) return hasBrother? INT_MAX: 0;
    return 1 + min(minDepth(root->left, root->right != nullptr), minDepth(root->right, root->left != nullptr));
}

int Solution5_1::minDepth(TreeNode *root) {
    return minDepth(root, false);
}


