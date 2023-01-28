#include<iostream>
#include<bits/stdc++.h>
//Minimum Path Sum LeetCode 64

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization
class Solution {
public:
    int minPath(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        //Base
        if(row == 0 && col == 0) return grid[0][0];
        
        if(row < 0 || col < 0 ){
            //Invalid index
            //If it goes out of index, we do not consider that path
            /*And since we are returning min of top and left path, we need to return very high
            value, so that path is not considered*/
            return 1e6;
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        
        //Work
        //Consider the current number and check for its smaller problem
        //i.e. minPath to reach the grid[i-1][j]
        int top = grid[row][col] + minPath(row-1, col, grid, dp);
        
        //Current number + minPath to reach grid[i][j-1] from grid[0][0]
        int left = grid[row][col] + minPath(row, col-1, grid, dp);
        
        return dp[row][col] = min(top, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
        
        return minPath(m-1, n-1, grid, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation approach 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //BASE CASE
        //at starting index
        dp[0][0] = grid[0][0];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //If it is invalid index, we will not consider that path
                int left = 1e6;
                int top = 1e6;
                
                if(i==0 && j==0) continue;
                
                //Considering we go left
                if(j>0) left = grid[i][j] + dp[i][j-1];
                
                //Considering we go top
                if(i>0) top = grid[i][j] + dp[i-1][j];
                
                dp[i][j] = min(top, left);
            }
        }
        
        return dp[m-1][n-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/