#include<iostream>
#include<bits/stdc++.h>
//House Robber 2 Leetcode 213

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed. All houses at this place are arranged in a circle. That means the first house is 
the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Approach:
Similar approach to house robber I.
Since, the houses are arranged in a circle, if we take the first house, we can't pick the
last house or vice versa.
Make 2 seperate vectors,1st which includes 1st house and everyone except the last house.
2nd in which it includes last house and everyone except 1st house.
All other logic is same.
*/

class Solution {
public:
    int maxRob(int house, vector<int> v, vector<int>& dp){
        //Base case
        if(house == 0){
            //If it reaches here, means 1 was not picked
            return v[0];
        }else if(house < 0){
            return 0;
        }
        
        if(dp[house] != -1){
            return dp[house];
        }
        
        //2 cases
        //take : since we took the house, we cant consider adjacent house
        int takeSum = maxRob(house-2, v, dp) + v[house];
        
        //not take : since we didn't took the house, we can consider adjacent house
        int notTakeSum = maxRob(house-1, v, dp) + 0;
        
        return dp[house] = max(takeSum, notTakeSum);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> fhouse, lhouse;
        
        //For memoization
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        
        for(int i=0; i<n; i++){
            if(i != 0){
                //Considering the last house 
                lhouse.push_back(nums[i]);
            }
            if(i != n-1){
                //Considering the first house
                fhouse.push_back(nums[i]);
            }
        }
        
        //First house considered : last house will now be n-2
        int fhouseAns = maxRob(n-2, fhouse, dp1);
        //Last house considered : last house will now be n-2
        int rhouseAns = maxRob(n-2, lhouse, dp2);
        
        return max(fhouseAns, rhouseAns);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/