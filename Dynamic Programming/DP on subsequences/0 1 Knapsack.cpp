#include<iostream>
#include<bits/stdc++.h>
//0-1 Knapsack Problem

/*
You are given weights and values of N items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights 
associated with N items respectively. Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller 
than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int maxProfit(int idx, int weight, int wt[], int val[], int n
    , vector<vector<int>>& dp){
        if(idx == n){
            return 0;
        }
        
        if(dp[idx][weight] != -1){
            return dp[idx][weight];
        }
        
        //take 
        int take = 0;
        if(wt[idx] <= weight){
            take = maxProfit(idx+1, weight-wt[idx],wt,val,n, dp) + val[idx];
        }
        
        
        //not take
        int notTake = maxProfit(idx+1, weight, wt, val,n, dp) + 0;
        
        return dp[idx][weight] = max(take, notTake);
    }
    
    int maxProfitBU(int W, int wt[], int val[], int n){
        
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        
        //Base cases
        //If we are only considering last idx: only 1 item
        for(int i=0; i<=W; i++){
            //i is the weight that bag can withstand
            if(wt[n-1] <= i){
                //if we have bag that can hold weight more or equal to item -> take
                dp[n-1][i] = val[n-1];
            }else{
                dp[n-1][i] = 0;
            }
        }
        
        //If bag can hold nothing(wt=0)
        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=W; j++){
                int take = 0;
                if(wt[i] <= j){
                    take = dp[i+1][j-wt[i]] + val[i];
                }
                
                int notTake = dp[i+1][j] + 0;
                
                dp[i][j] = max(take, notTake);
            }
        }
        
        return dp[0][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        //Memoization
        // vector<vector<int>> dp(n, vector<int> (W+1, -1));
        //return maxProfit(0, W, wt, val, n, dp);
    
        //Bottomup: tabulation
        return maxProfitBU(W, wt, val, n);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/