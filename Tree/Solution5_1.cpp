//
// Created by Cloud on 2015-08-10.
//

#include "Solution5_1.h"
#include <iostream>
#include <stack>

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
