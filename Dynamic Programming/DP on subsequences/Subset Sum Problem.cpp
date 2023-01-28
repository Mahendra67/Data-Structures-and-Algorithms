#include<iostream>
#include<bits/stdc++.h>
//Subset Sum Problem GFG

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset 
of the given set with sum equal to given sum. 
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization
class Solution{   
public:
    //n-1 to 0
    bool Subset(int idx, vector<int>& arr,int target, vector<vector<int>>& dp){
        //base cases
        if(target == 0){
            //we have found a subset of sum 'target', return true
            return true;
        }
        
        if(idx == 0){
            //When index is zero but target is still not zero:
            //Means the element at index 0 must be equal to current target to return true
            //else return false
            return (arr[0] == target);
        }
        
        
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        
        //not take 
        bool notTake = Subset(idx-1, arr, target, dp);
        
        bool take = false;
        //Only take if target is smaller than element at current index
        //Thats why take is at default false;
        if(target > arr[idx]){
            take = Subset(idx-1, arr, target - arr[idx], dp);
        }
        
        
        return dp[idx][target] = (take || notTake);
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        //For memoization
        /*
        Changing states : idx, target in recursion.
        'idx' can have values from 0 to maxIndex of array. (Here n is 100) -> take 101
        'target' can have values from 0 to targetMaxValue (e.g. 
        
        given sum <=1e5) -> take 1e5+1 (as it is inclusive)
        */
        
        vector<vector<int>> dp(n, vector<int> (1e5+1, -1));
        
        return Subset(n-1, arr, sum, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//tabulation
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        //Step 1: Declare dp array of same size
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        
        //Step 2: Write all the base cases
        //dp[index][sum]    
        
        //if(target==0) -> return true;
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        //2nd base case: if(idx==0){ return (arr[0]==target) }
        //At index 0, target = arr[0] will be true.
        //grid[idx=0][target=arr[0]]
        dp[0][arr[0]] = true;
        
        //Step3: Form the nested loop
        //For index state
        for(int i=1; i<n; i++){
            //For target state
            for(int target=1; target<=sum; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= arr[i]){
                    take = dp[i-1][target - arr[i]];
                }
                
                dp[i][target] = (notTake || take);
            }
        }
        
        return dp[n-1][sum];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/