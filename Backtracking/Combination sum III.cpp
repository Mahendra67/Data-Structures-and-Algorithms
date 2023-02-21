#include<iostream>
#include<bits/stdc++.h>
//Combination Sum III Leetcode 216

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void cs3(int idx, vector<int>& nums, int k, int target, vector<int>& temp){
        //Base cases
        int n = nums.size();
        
        //First check if k numbers have been picked
        if(k == 0){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        int FirstOutOfBoundIdx = n;
        if(idx == FirstOutOfBoundIdx){
            return;
        }
        
        //take
        if(nums[idx] <= target){
            temp.push_back(nums[idx]);
            cs3(idx+1, nums, k-1, target - nums[idx], temp);
            temp.pop_back();
        }
        
        //not take
        cs3(idx+1, nums, k, target, temp);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        
        vector<int> temp;
        
        cs3(0, nums, k, n, temp);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/