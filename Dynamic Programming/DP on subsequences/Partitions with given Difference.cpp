#include<iostream>
#include<bits/stdc++.h>
//Partitions with given difference GFG

/*
Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. 
Let the sum of the element of these two subsets be S1 and S2. 

Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference 
S1 and S2 is equal to d. since the answer may be large return it modulo 10^9 + 7.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization approach:

/*
We need to find no. of subsets such that s1-s2 = d.

(total-s2) - s2 = d
total -  2s2 = d
s2 = (total - d)/2

So, we need to find subset whose sum is equal to (total - d)/2. Count them.

Since, in original array every number is positive integer, hence the summation of subsets formed 
from it must also be a positive integer.

Hence, only those subsets will be valid who are not in fraction or negative.
For, it to not be a fraction : (total-d) must be an even value. (Since we are dividing by 2)

Check if (target-d) is positive, if yes then only declare the dp array.
*/
class Solution {
  public:
    int mod = 1e9 + 7;
  
    int subset(int idx, vector<int>& nums, int target, vector<vector<int>>& dp){
        //Base cases
        if(idx == 0){
            //Since arr[i] can be zero, we need to check till last index
            if(target == 0 && nums[0] == 0) return 2;
            //If the target becomes zero (in previous idx (not 0th))
            //Or if the target hasn't yet become zero, but first element is equal to target
            if(target == 0 || nums[0]==target) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        //take
        int take = 0;
        if(target >= nums[idx]){
            take = subset(idx-1, nums, target-nums[idx], dp);
        }
        
        //not take
        int notTake = subset(idx-1, nums, target, dp);
        
        return dp[idx][target] = (take + notTake)%mod;
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        //First find the sum of original array
        
        int TotalSum = 0;        
        for(auto &it: arr){
            TotalSum += it;
        }
        
        int target = (TotalSum-d)/2;
        
        //If summation is odd, then target will be in fraction. No point in searching
        if((TotalSum-d) % 2 != 0){
            return 0;
        }
        
        //If target is negative return 0
        if(target < 0){
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        return subset(n-1, arr, target, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation

class Solution {
  public:
    int mod = 1e9 + 7;
  
    int countPartitions(int n, int d, vector<int>& arr) {
        //First find the sum of original array
        
        int TotalSum = 0;        
        for(auto &it: arr){
            TotalSum += it;
        }
        
        int target = (TotalSum-d)/2;
        
        //If summation is odd, then target will be in fraction. No point in searching
        if((TotalSum-d) % 2 != 0){
            return 0;
        }
        
        //If target is negative return 0
        if(target < 0){
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        
        int lastIdx = n-1;
        
        /*
        Each grid cell meaning:
        grid[i][target] -> 
        no. of ways it can form subset with sum=target considering arr from 0th index to ith index
        */
        
        //Base cases
        //IF the first element is 0 : 2 ways:either we consider the zero or we dont(target is zero at 0,0)
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        //If first element is equal to target: make sure the target is also not zero -> else it will update
        //the above base case
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int notTake = dp[i-1][t];
                int take = 0;
                if(t >= arr[i]){
                    take = dp[i-1][t-arr[i]];
                }
                
                dp[i][t] = (take + notTake)%mod;
            }
        }
        
        return dp[lastIdx][target];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/