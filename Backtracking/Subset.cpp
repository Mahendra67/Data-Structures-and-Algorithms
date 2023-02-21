#include<iostream>
#include<bits/stdc++.h>
//Subset Leetcode 78

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:    
    void subset(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        //base case
        if(idx == nums.size()){
            ans.push_back(temp);
            //Backtracking
            return;
        }
        
        
        //take
        temp.push_back(nums[idx]);
        subset(idx+1, nums, ans, temp);
        
        //not take
        temp.pop_back();
        subset(idx+1, nums, ans, temp);
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        
        subset(0, nums, ans, temp);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/