#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifndef SOLUTION7_H
#define SOLUTION7_H
class Solution7 {
public:
    // Search for a Range
    vector<int> searchRange(vector<int> &nums, int target);
    vector<int> searchRangeSTL(vector<int> &nums, int target);
    // Search a 2D Matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target);
};
#endif //SOLUTION7_H