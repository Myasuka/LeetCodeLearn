#include <iostream>
#include <vector>
#include <stack>
#include <map>

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

    multimap<int, int> result;
    result.insert(pair<int,int>(1, 10));
    result.insert(pair<int,int>(1, 11));
    result.insert(pair<int,int>(2, 11));
    result.insert(pair<int,int>(3, 15));
    // use 'find' and 'count'
    auto iter1 = result.find(1);
    int cnt = result.count(1);
    cout << "method 1" << endl;
    for(int i =0; i< cnt; i++){
        cout << iter1->first << ", " << iter1->second << endl;
        ++ iter1;
    }

    // use lower_bound and upper_bound
    cout << "method 2" << endl;
    auto iter2low = result.lower_bound(1);
    auto iter2upp = result.upper_bound(1);
    for(auto i = iter2low; i != iter2upp; i ++){
        cout << i->first << ", " << i->second << endl;
    }

    // use equal_range
    cout << "method 3" << endl;
    auto pairiter3 = result.equal_range(1);
    for(auto i = pairiter3.first; i != pairiter3.second; i++){
        cout << i->first << ", " << i->second << endl;
    }
    return 0;
}