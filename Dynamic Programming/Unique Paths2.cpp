#include<iostream>
#include<bits/stdc++.h>
//Unique Paths 2 Leetcode 63

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot 
include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization
class Solution {
public:
    int NumPaths(int row, int col, vector<vector<int>>& obstacleGrid, 
                vector<vector<int>>& dp){
        
        //Extra base case than UNIQUE PATH I
        if(row >=0 && col>=0 && obstacleGrid[row][col] == 1){
            //can't move further from current block, return 
            return 0;
        }
        //We have to check the above condition first
        //Edge case:
        /*
        [[1]] -> m = 1, n = 1
        If the below condition was checked first, it would return 1 -> wrong answer
        */
        
        //Base case
        if(row == 0 && col == 0){
            //reached start
            return 1;
        }
        
        if(row < 0 || col < 0) {
            return 0;
        }
        
        
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        
        //Work
        int top = NumPaths(row-1, col, obstacleGrid, dp);
        
        int left = NumPaths(row, col-1, obstacleGrid, dp);
        
        return dp[row][col] = top + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        //Memoization
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return NumPaths(m-1, n-1, obstacleGrid, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation approach
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>& grid = obstacleGrid;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        //Base case
        //From grid[0][0] to grid[0][0] -> only 1 way (if grid[0][0] is empty space)
        if(grid[0][0] != 1){
            dp[0][0] = 1;
        }else{
            dp[0][0] = 0;
            return 0;
        }
        
        for(int i=0; i<m; i++){
            int left = 0;
            int top = 0;
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                
                //Check if there is obstacle present or not
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(j>0) left = dp[i][j-1];
                if(i>0) top = dp[i-1][j];
                
                dp[i][j] = left + top;
            }
        }
        
        return dp[m-1][n-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/