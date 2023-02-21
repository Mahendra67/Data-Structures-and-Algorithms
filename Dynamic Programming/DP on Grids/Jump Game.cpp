#include<iostream>
#include<bits/stdc++.h>
//Jump Game Leetcode 55

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element 
in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:
    bool ReachEnd(int idx, vector<int>& nums, int maxIdx, vector<int>& dp){
        //Base cases
        if(idx == maxIdx){
            return true;
        }
        
        if(idx > maxIdx){
            return false;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        
        
        //jump
        bool CanYouReach = false;
        int possibleJump = nums[idx];
        
        for(int i=1; i<=possibleJump; i++){
            int jump = idx + i;
            // CanYouReach = ReachEnd(jump, nums, maxIdx) || CanYouReach;
            
            //Small optimization
            CanYouReach = ReachEnd(jump, nums, maxIdx, dp);
            
            if(CanYouReach == true){
                return true;
            }
        }
        
        return dp[idx] = CanYouReach;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = n - 1;
        
        vector<int> dp(n, -1);
        
        return ReachEnd(0, nums, maxIdx, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Tabulation
class Solution {
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        
        //dp array
        vector<int> dp(n, 0);
        
        //Base cases
        //Reached the last cell -> true
        int lastIdx = n-1;
        dp[lastIdx] = true;
        
        
        int secondLastIdx = n-2;
        for(int i=secondLastIdx; i>=0; i--){
            bool ReachCurrCell = false;
            int possibleJump = nums[i];
            
            for(int jump=1; jump<=possibleJump; jump++){
                //Using newPos index to fill i index
                int newPos = i + jump;
                
                if(newPos <= lastIdx){
                    ReachCurrCell = dp[newPos] || ReachCurrCell;
                }
                
                //Small optimization
                if(ReachCurrCell == true){
                    break;
                }
            }
            
            dp[i] = ReachCurrCell;
        }
        
        return dp[0];
    }
};


/*-----------------------------------------------------------------------------------------------------------*/