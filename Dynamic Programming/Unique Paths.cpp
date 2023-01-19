#include<iostream>
#include<bits/stdc++.h>
//Unique Paths Leetcode 62

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach 
the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//memoization
class Solution {
public:
    int NoOfWays(int row, int col, vector<vector<int>>& dp){
        //Base case : It reaches grid[0][0]
        if(row == 0 && col == 0){
            return 1;
        }
        
        //If it goes out of bound
        if(row < 0 || col < 0){
            //Invalid way
            return 0;
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        //If starting from [0][0] -> we can move down or right
        //Hence, starting from [m-1][n-1] -> we can move up or right
        int moveLeftWays = NoOfWays(row, col-1, dp);
        int moveTopWays = NoOfWays(row-1, col, dp);
        
        return dp[row][col] = moveLeftWays + moveTopWays;
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        
        return NoOfWays(m-1, n-1, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//tabulation appraoch
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //Base case
        //Only 1 way to go from grid[0][0] to grid[0][0]
        dp[0][0] = 1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int left = 0;
                int top = 0;
                if(i==0 && j==0){
                    continue;
                }else{
                    if(j>0){
                        left = dp[i][j-1];
                    } 
                    if(i>0){
                        top = dp[i-1][j];
                    } 
                    
                    dp[i][j] = left + top;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/