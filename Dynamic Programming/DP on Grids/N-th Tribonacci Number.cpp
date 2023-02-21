#include<iostream>
#include<bits/stdc++.h>
//N-th Tribonacci Number Leetcode 1137

/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
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
    int tri(int n, vector<int>& dp){
        //Base case
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = tri(n-1, dp) + tri(n-2, dp) + tri(n-3, dp);
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        
        return tri(n, dp);
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
    int tribonacci(int n){
        //Edge cases
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        vector<int> dp(n+1, 0);
        
        //Base cases
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        //n state can have values from 0 to n
        //but 0 to 2 cells in dp has already been filled/solved
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/