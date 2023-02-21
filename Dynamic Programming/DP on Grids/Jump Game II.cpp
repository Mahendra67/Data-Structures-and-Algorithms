#include<iostream>
#include<bits/stdc++.h>
//Jump game II Leetcode 45

/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], 
you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Memoization
class Solution {
public:
    int minJump(int idx, vector<int>& nums, int n, vector<int>& dp){
        //Base cases
        int lastIdx = n-1;
        if(idx == lastIdx){
            //Already at the destination index, no need for further steps
            return 0;
        }
        
        //out of bound: dont consider this path
        if(idx > lastIdx){
            return 1e8;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        
        //jump
        int minStep = 1e8;
        
        int possibleSteps = nums[idx];
        
        for(int i=1; i<=possibleSteps; i++){
            int steps = minJump(idx+i, nums, n, dp);
            minStep = min(steps, minStep);
        }
        
        return dp[idx] = minStep+1;
    }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        //n spaces are required (not n+1) as it never access the last index, it return 1 directly (line 7)
        vector<int> dp(n, -1);
        

        int ans = minJump(0, nums, n, dp);
        
        //If ans is still 1e8 : only possible if first element is zero
        if(ans == 1e8){
            return 0;
        }else{
            return ans;
        }
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Tabulation approach
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        
        //Base case
        int lastIdx = n-1;
        //Already on last cell, no need to move extra steps
        dp[lastIdx] = 0;
        
        int secondLastIdx = n-2;
        for(int i=secondLastIdx; i>=0; i--){
            
            int minSteps = 1e8;
            int possibleJump = nums[i];
            
            for(int jump=1; jump<=possibleJump; jump++){
                int newPos = i + jump;
                if(newPos <= lastIdx){
                    minSteps = min(minSteps, dp[newPos]);
                }
            }
            
            dp[i] = minSteps + 1;
        }
        
        return dp[0];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/
