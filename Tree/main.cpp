#include <iostream>
#include <vector>
#include <stack>

using namespace std;


#include "Solution5_1.h"

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(3);
    root->right = p;
    p->left = q;
    Solution5_1 *s = new Solution5_1();


//    vector<int> result2;
//    s->preOrderRecurive(root, result2);
//    cout << "result2 size: " << result2.size() << endl;
//    for (int i = 0; i < result2.size(); i++) {
//        cout << result2[i] << ",";
//    }
//    cout << endl;

//    vector<int> result3 = s->inOrderRecurive(root);
//    cout << "result3 size: " << result3.size() << endl;
//    for (int i = 0; i < result3.size(); i++) {
//        cout << result3[i] << ",";
//    }
//    cout << endl;

//    vector<int> postResult = s->postOrderTraversal(root);
//    cout << "postResult size: " << postResult.size() << endl;
//    for (int i = 0; i < postResult.size(); i++) {
//        cout << postResult[i] << ",";
//    }
//    cout << endl;

    vector<vector<int>> levelResult = s->levelOrder(root);
    cout << "levelResult size: " << levelResult.size() << endl;
    for (int i = 0; i < levelResult.size(); i++) {
        for (int j = 0; j < levelResult[i].size(); j++) {
            cout << levelResult[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}