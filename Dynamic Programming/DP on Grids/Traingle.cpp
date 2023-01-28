#include<iostream>
#include<bits/stdc++.h>
//Triangle LeetCode 120

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Starting point is fixed, but ending point is variable.
Hence, it is preferred to start from 0,0
*/

class Solution {
public:
    int minPath(int row, int col,int maxRow, vector<vector<int>>& grid,
               vector<vector<int>>& dp){        
        //Base case
        if(row == maxRow) return grid[row][col];
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        //Work
        int i = grid[row][col] + minPath(row+1, col, maxRow, grid, dp);
        
        int i1 = grid[row][col] + minPath(row+1, col+1, maxRow, grid, dp);
        
        return dp[row][col] = min(i, i1);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        //memoization
        //not (m*n) where n = triangle[0].size - 1 as it is a triangle (variable col number) 
        vector<vector<int>> dp(m, vector<int> (m, -1));
        
        return minPath(0, 0, m-1, triangle, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
Thumb rule for tabulation : Opposite of Recursion
e.g. if in recursion, you went from 0 to n-1
then, tabulation will be from m-1 to 0
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //Base case
        //Since, in recursion we went from 0,0 to last row
        //Hence, in tabulation, base cases would be the elements of the last row 
        for(int i=0; i<n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        
        
        for(int i=m-2; i>=0; i--){
            for(int j=triangle[i].size()-1; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diaRightDown = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, diaRightDown);
            }
        }
        
        
        return dp[0][0];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/