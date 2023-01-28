#include<iostream>
#include<bits/stdc++.h>
//House Robber LeetCode 198

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police if two adjacent houses were 
broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of 
money you can rob tonight without alerting the police.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    //Similar to subsequence problem : pick and not pick
    int maxMoney(int idx, vector<int>& nums, vector<int>& dp){
        //Base case
        if(idx == 0){
            //If it reaches zero, that means 1 has not been picked, so we can return arr[0]
            return nums[idx];
        }
        else if(idx < 0){
            return 0;
        } 
        
        //Check if already solved
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        
        //pick
        //If currNode is picked, we can't pick adjacent node, hence jump 2 back
        //Since we are picking currNode, sum increases by currNode value
        int pick = nums[idx] + maxMoney(idx - 2, nums, dp);
        
        //not pick
        //If currNode is not picked, we can pick adjacent node, hence jump 1 back
        //Since currNode is not picked, currNode value is taken as 0
        int notPick = 0 + maxMoney(idx - 1, nums, dp);
        
        return dp[idx] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return maxMoney(n-1, nums, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation Approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        
        //Base case
        dp[0] = nums[0];
        //If negative -> give 0
        
        for(int i=1; i<n; i++){
            int pick = nums[i];
            //Since, picking currNode -> go -2 back
            //Add prev sum only if it is valid index (not negative)
            if(i-2 >= 0){
                pick = pick + dp[i-2];
            }
            
            int notPick = 0 + dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation Approach : Space Optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // vector<int> dp(n, 0);
        
        //Base case
        int prev = nums[0];
        //If negative -> give 0
        int prev2 = 0;
        
        for(int i=1; i<n; i++){
            int pick = nums[i];
            //Since, picking currNode -> go -2 back
            //Add prev2 sum only if it is valid index (not negative)
            if(i-2 >= 0){
                pick = pick + prev2;
            }
            
            int notPick = 0 + prev;
            
            int curr = max(pick, notPick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/