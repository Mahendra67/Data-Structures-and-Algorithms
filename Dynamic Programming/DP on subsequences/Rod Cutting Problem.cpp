#include<iostream>
#include<bits/stdc++.h>
//Rod Cutting Problem GFG

/*
Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece 
of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: Consider 1-based indexing.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution{
    public:

    //memoization
    int maxProfit(int idx, int length, int price[], int n, vector<vector<int>>& dp){
        //1 based indexing
        int cuttingLength = idx+1;
        
        //base cases
        if(idx == n-1){
            return (length/cuttingLength)*price[idx];
        }
        
        if(dp[idx][length] != -1){
            return dp[idx][length];
        }
        
        
        //cut it at the length (idx+1) -> can cut it at that length multiple times
        int cut = 0;
        if(cuttingLength <= length){
            cut = maxProfit(idx, length - cuttingLength, price, n, dp) + price[idx]; 
        }
        
        //dont cut it
        int dontCut = maxProfit(idx+1, length, price, n, dp) + 0;
        
        return dp[idx][length] = max(cut, dontCut);
    }
    
    //tabulation
    int maxProfitBU(int price[], int n){
        //By observing base cases, idx can go upto n-1
        vector<vector<int>> dp(n, vector<int> (n+1, 0));
        
        //base cases
        // i is length of rod
        int maxRodLength = n;
        for(int i=0; i<n; i++){
            dp[n-1][i] = 0;
        }
        //only last grid cell will be possible according to given conditions
        //left side n is length at which it is cut
        //right side n-1 is idx of last element
        dp[n-1][n] = price[n-1];
        
        //2nd base case: if intially rod has no length(0) -> not possible to gain any profit
        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        
        //filling
        //i means we are considering indexes from i to n-1
        for(int i=n-2; i>=0; i--){
            int cuttingLength = i+1;
            //j is length of current rod
            for(int j=1; j<=n; j++){
                int cut = 0;
                if(cuttingLength <= j){
                    cut = dp[i][j-cuttingLength] + price[i];
                }
                int dontCut = dp[i+1][j] + 0;
                
                dp[i][j] = max(cut, dontCut);
            }
        }
        
        return dp[0][n];
    }
    
    int cutRod(int price[], int n) {
        //memoization
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return maxProfit(0, n, price, n, dp);
        
        //tabulation
        return maxProfitBU(price, n);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/