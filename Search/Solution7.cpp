#include "Solution7.h"

    int getPos(int left, int right){
        return (right - left)/2 + left;
    }


    int findMax(vector<int> &nums, int target, int left, int right){
        int pos = (right - left) / 2 + left;
        while(left < right){
        if(nums[pos] > target){
            right = pos - 1;
            pos = getPos(left, right);
        }else {
            left = pos + 1;
            pos = getPos(left, right);
        }
        }
        return pos;
    }
    
    int findMin(vector<int> &nums, int target, int left, int right){
        int pos = (right - left) / 2 + left;
        while(left < right){
        if(nums[pos] >= target){
            right = pos - 1;
            pos = getPos(left, right);
        }else {
            left = pos + 1;
            pos = getPos(left, right);
        }
        }
        return pos;
    }
    

vector<int> Solution7::searchRange(vector<int> &nums, int target){
        int low = -1,high = -1;
        int left = 0;
        int right = nums.size() - 1;
        int pos = getPos(left, right);
        while(left <= right){
            if(nums[pos] > target){
                right = pos - 1; 
                pos = getPos(left, right);
            }else if(nums[pos] < target){
                left = pos + 1;
                pos = getPos(left, right);
            }else {
                if(pos == right){
                    high = right;
                }else high = findMax(nums, target, pos + 1, right);
                if(pos == left){
                    low = left;
                }else
                low = findMin(nums, target, left, pos - 1);
                break;
            }
        }
        if(high != -1 && nums[high] != target) high--;
        if(low != -1 && nums[low] != target) low++;
        vector<int> result;
        result.push_back(low);
        result.push_back(high);
        return result;
    }
    


vector<int> Solution7::searchRangeSTL(vector<int> &nums, int target){
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        vector<int> result;
        if(nums[low] != target){
            low = -1;
            high = -1;
        }
        result.push_back(low);
        result.push_back(high);
        return result;
}

bool Solution7::searchMatrix(vector<vector<int>>& matrix, int target){
    int low = 0;
        int high = matrix.size() - 1;
        int pos = getPos(low, high);
        while(low < high){
            if(matrix[pos][0] > target){
                high = pos - 1;
                pos = getPos(low, high);
            }else if(matrix[pos][0] < target){
                low = pos + 1;
                pos = getPos(low, high);
            }else return true;
        }
        int p;
        if(matrix[low][0] > target){
            p = low - 1;
        }else p = low;
        if(p < 0) return false;
        vector<int> v = matrix[p];
        /**
        if(find(v.begin(), v.end(), target) != v.end()) {
            return true;
        }
        else return false;
        **/
        low = 0;
        high = v.size() -1;
        pos = getPos(low, high);
        while(low <= high){
            if(v[pos] > target){
                high = pos - 1;
                pos = getPos(low, high);
            }else if(v[pos] < target){
                low = pos + 1;
                pos = getPos(low, high);
            }else return true;
        }
        return false;
    }
