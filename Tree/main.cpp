#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <set>
#include <list>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unistd.h>


using namespace std;


#include "Solution5_1.h"

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
typedef vector<pair<int, int>> vp;
vector<vp> getWays(set<pair<int, int>> &s, pair<int, int> node, int n, int m){
    if(s.find(node) != s.end()) return vector<vp>();
    int n1 = node.first;
    int n2 = node.second;
    if(n1 >= n || n2 >= m) return vector<vp>();
    if((n1 == n - 1 )&& (n2 = m - 1)) {
        cout<< "get the final location!" << endl;
        vector<vp> result;
        vp v{make_pair(n1, n2)};
        result.push_back(v);
        return result;
    }
    auto r = getWays(s, make_pair(n1, n2 + 1), n , m);
    auto b = getWays(s, make_pair(n1 + 1, n2), n , m);
    if(!r.empty()){
        for(int i = 0; i < r.size(); i++){
            r[i].push_back(make_pair(n1, n2));
        }
    }
    if(!b.empty()){
        for(int i = 0;i< b.size();i ++){
            b[i].push_back(make_pair(n1, n2));
        }
    }
    if(r.empty() && b.empty()) return vector<vp>();
    r.insert(r.end(), b.begin(), b.end());
    return r;
}

void display(string &s){
    cout << s << endl;
}

struct TreeNode2{
    int value;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2(int x): value(x), left(nullptr), right(nullptr) {}
};


struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};
class LRUcache{
private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;

public:
    int get(int key){
        if( cacheMap.find(key) == cacheMap.end()) return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }
};
int main() {

    string s("abc");
    cout << s.find('b') << endl;
    s.erase(s.begin(), s.begin() + 3);
    cout << s << endl;
    cout << s.size() << endl;

//    cout << "begining of the program" << endl;
//    int count = 0;
//    pid_t pid = fork();
//    if(pid == 0){
//        for (int i = 0; i < 100; ++i) {
//            cout<< "child process, count: " << ++count << endl;
//        }
//    }else if(pid > 0){
//        for (int j = 0; j < 100; ++j) {
//            cout<< "parent process, count: " << ++count << endl;
//        }
//    }else {
//        cout << "fork failed" << endl;
//        return -1;
//    }
//    cout << "end of the program" << endl;
//    vector<string> vs{"123", "", "ab", "  cd"};
//    for(string s: vs){
//        cout << s << endl;
//    }
//    multimap<int, int> m;
//    m.insert(make_pair(2, 3));
//    m.insert(make_pair(2, 4));
//    m.insert(make_pair(3, 4));
//    cout << "m count 2: " << m.count(2) << endl;
//
//    auto it = m.lower_bound(2);
//    auto it2 = m.upper_bound(2);
//    for (auto j = it; j != it2; ++j) {
//        cout << (*j).first << ',' << (*j).second << endl;
//    }
//    auto it3 = m.equal_range(2);
//    for(auto j = it3.first; j != it3.second; ++j){
//        cout << (*j).first << ',' << (*j).second << endl;
//    }
//
//    for(pair<int, int> i: m){
//        cout << i.first << "," << i.second << endl;
//    }

//    cout<< INT_MAX << endl;
//    cout << abs(10 - 12) << endl;
//    string s("1234567");
//    vector<char> v{'1', '2', '3', '4', '5', '6', '7'};
//    cout << "v find " << (find(v.begin(), v.end(), '1') - v.begin()) << endl;
//    cout << distance(find(v.begin(), v.end(), '1'), v.begin()) << endl;
//    cout << s.find('1') << endl;
//    cout << s.find('5') << endl;
//    cout << s.find('7') << endl;
//    cout << (s.find('8') == string::npos) << endl;
//    display((string) "nihao");
//    vector<int> a;
//    vector<int> b{3, 4};
//    a.insert(a.end(), b.begin(), b.end());
//    b.insert(b.end(), a.begin(), a.end());
//    for(int i:a) cout << i << " ";
//    cout << endl;
//    for(int i:b) cout << i << " ";
//    cout << endl;
//    set<pair<int, int>> s;
//    s.insert(make_pair(1, 1));
//    vector<int> v{2, 1};
//    for(int i:v) cout << i << ", ";
//    cout << endl;
//    vector<int> vv(2, 1);
//    for(int i:vv) cout << i << ", ";
//    cout << endl;
//    auto result = getWays(s, make_pair(0,0), 3, 3);
//    cout << "complie finished!" << endl;
//    for(vp i: result){
//        for(pair<int, int> v: i){
//            cout << v.first << "," << v.second<< " -> ";
//        }
//        cout << endl;
//    }
//    TreeNode *root = new TreeNode(1);
//    TreeNode *p = new TreeNode(2);
//    TreeNode *q = new TreeNode(3);
//    root->right = p;
//    p->left = q;
//    Solution5_1 *s = new Solution5_1();


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