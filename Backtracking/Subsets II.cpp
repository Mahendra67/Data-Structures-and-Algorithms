#include<iostream>
#include<bits/stdc++.h>
//Subsets II Leetcode 90

/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Before adding the subset to ans vector, sort the subset formed, then check if it is already present in ans.

class Solution {
public:
    void subset(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, 
                int maxIdx){
        //Base cases
        if(idx > maxIdx){
            //{1,2} is same as{2,1}
            //Hence, sort the temp vector
            sort(temp.begin(), temp.end());
            
            
            //Check if it is already in answer vector
            int m = ans.size();
            for(int i=0; i<m; i++){
                if(ans[i] == temp){
                    return;
                }
            }
            
            ans.push_back(temp);
            return;
        }
        
        
        //take
        temp.push_back(nums[idx]);
        subset(idx+1, nums, ans, temp, maxIdx);
        
        
        //not take
        temp.pop_back();
        subset(idx+1, nums, ans, temp, maxIdx);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int maxIdx = nums.size()-1;
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        subset(0, nums, ans, temp, maxIdx);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Sort the given nums vector first -> no need to sort the subset formed

class Solution {
public:
    void subset(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, 
                int maxIdx){
        //Base cases
        if(idx > maxIdx){
            //{1,2} is same as{2,1}
            // //Hence, sort the temp vector
            // sort(temp.begin(), temp.end());
            //Rather than sorting here, just sort the main nums vector
            
            //Check if it is already in answer vector
            int m = ans.size();
            for(int i=0; i<m; i++){
                if(ans[i] == temp){
                    return;
                }
            }
            
            ans.push_back(temp);
            return;
        }
        
        
        //take
        temp.push_back(nums[idx]);
        subset(idx+1, nums, ans, temp, maxIdx);
        
        
        //not take
        temp.pop_back();
        subset(idx+1, nums, ans, temp, maxIdx);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int maxIdx = nums.size()-1;
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        //Sort the main nums vector 
        /*
        This is done to avoid sorting at each temp vector formation (when it reaches idx>maxIdx)
        */
        sort(nums.begin(), nums.end());
        
        subset(0, nums, ans, temp, maxIdx);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/