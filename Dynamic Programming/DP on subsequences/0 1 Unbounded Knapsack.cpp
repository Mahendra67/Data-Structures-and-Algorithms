#include<iostream>
#include<bits/stdc++.h>
//Unbounded Knapsack : 0-1 Knapsack But you can take an element infinite times

/*
Given a set of N items, each with a weight and a value, represented by the array w[] and val[] 
respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the 
maximum profit.
Note: Each item can be taken any number of times.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution{
public:
    int maxProfit(int idx, int Weight, int val[], int wt[], int n, vector<vector<int>>& dp){
        if(idx == n-1){
            //if bag cant withstand the weight it will return 0
            //else, it will take it as many times it can be picked
            return (Weight/wt[n-1])*val[n-1];
        }
        
        if(dp[idx][Weight] != -1){
            return dp[idx][Weight];
        }
        
        
        //take -> we can take indefinite times
        int pick = 0;
        
        if(wt[idx] <= Weight){
            pick = maxProfit(idx, Weight-wt[idx],val,wt,n, dp) + val[idx];
        }
        
        
        //not take
        int notPick = maxProfit(idx+1, Weight,val,wt,n, dp) + 0;
        
        return dp[idx][Weight] = max(pick,notPick);
    }
    
    int maxProfitBU(int n, int W, int val[], int wt[]){
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        
        //Base cases
        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        
        //w is holding capacity of bag
        for(int w=0; w<W+1; w++){
            //you can only take if w is greater or equal to wt of last element
            if(wt[n-1] <= w){
                dp[n-1][w] = (w/wt[n-1])*val[n-1];
            }else{
                dp[n-1][w] = 0;
            }
        }
        
        
        //Now filling
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=W; j++){
                int take = 0;
                if(wt[i] <= j){
                    take = dp[i][j-wt[i]] + val[i];
                }
                
                int notTake = dp[i+1][j] + 0;
                
                dp[i][j] = max(take, notTake);
            }
        }
        
        return dp[0][W];
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        
        //Memoization
        // vector<vector<int>> dp(N, vector<int> (W+1, -1));
        // return maxProfit(0, W, val, wt, N, dp);
        
        //Tabulation
        return maxProfitBU(N, W, val, wt);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/