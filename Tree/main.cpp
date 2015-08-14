#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>

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

//    vector<vector<int>> levelResult = s->levelOrderQueue(root);
//    cout << "levelResult size: " << levelResult.size() << endl;
//    for (int i = 0; i < levelResult.size(); i++) {
//        for (int j = 0; j < levelResult[i].size(); j++) {
//            cout << levelResult[i][j] << ",";
//        }
//        cout << endl;
//    }
    vector<int> v = {1,2 ,3, 4, 5,6, 7, 8};
    vector<int> w = {1,2 ,3, 4, 5,6, 7, 8};
    cout <<w.end() - v.begin()<<endl;
    auto it = next(v.begin(), 4);
    auto t = *it;
    while(t){
        cout<<t<<" "<<endl;
        t = *(++it);
    }

    vector<int> f(10, 9);
    for(int i=0;i<f.size();i++){
        cout<< f[i] <<" "<<endl;
    }
    cout<< INT_MAX <<endl;
    return 0;


}