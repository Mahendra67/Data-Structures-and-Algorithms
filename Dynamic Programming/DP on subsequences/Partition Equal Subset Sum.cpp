#include<iostream>
#include<bits/stdc++.h>
//Partition Equal Subset Sum

/*
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Problem simplified:
We need to divide the array into 2 subsets such that sum of the elements in both subset is same.
Lets say the sum of array was 'x', then the sum of subsets should be 'x/2' each.

Also, it is given that only natural numbers are present, so if sum of original array comes out
to be ODD, then it is impossible to divide it into 2 equal sub subsets.(9/2 = 4.5 -> requires rational nos.)
If it is EVEN,
we need to find if 1 subset with the sum 'x/2' exists or not. If it exists, that means the remaining non-considered elements will form the second subset.

Approach: Find if subset with sum 'x/2' exists or not, if yes, return true. (x is total sum of original array)
*/
class Solution {
public:
    bool findSub(int idx, vector<int>& nums, int target, vector<vector<int>>& dp){
        //Base cases
        if(target == 0){
            return true;
        }
        
        if(idx == 0){
            //If target still not zero and you reached first element.
            //For target to become zero(take case), the first element has to be equal to curr target.
            if(target == nums[0]){
                return true;
            }
            return false;
        }
        
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        bool notTake = findSub(idx-1, nums, target, dp);
        
        bool take = false;
        if(target >= nums[idx]){
            take = findSub(idx-1, nums, target-nums[idx], dp);
        }
        
        return dp[idx][target] = (take || notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        //Find the sum of original array
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        //If sum is odd, not possible to split into 2 equal sum subsets
        if(sum%2 != 0){
            return false;
        }
        
        //FOR MEMOIZATION
        //idx can have values from 0 to n-1
        //target can have values from 0 to target(inclusive -> hence, take target+1)
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        
        //IF SUM IS EVEN
        //Now, find if a subset with target = sum/2 exists or not
        return findSub(n-1, nums, sum/2, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/