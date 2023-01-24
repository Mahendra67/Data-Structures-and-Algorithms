#include<iostream>
#include<bits/stdc++.h>
//Minimum Falling Path Sum 931 LeetCode

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. Specifically, the next element from position (row, col) 
will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Greedy is not used because there is no uniformity in changes
/*
1   3   4
2   4   1
90  30  3
Had we used greedy, it would have picked path: 1->2->30
But the min path is: 4->1->3
*/

/*
Approach:
For every element in first row, think of that element as fixed and find the minimum path to 
reach to that element from the last row.
Do this for every element in the first row, return the min path.
*/
class Solution {
public:
    int minPath(int row, int col, vector<vector<int>>& grid, int maxRow,
               vector<vector<int>>& dp){
        //Base case
        //As no. of rows = no. of columns
        if(col > maxRow || col < 0){
            return 1e6;
        }
        
        if(row == maxRow){
            return grid[row][col];
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        //Work   
        int way1 = grid[row][col] + minPath(row+1, col-1, grid, maxRow, dp);
        int way2 = grid[row][col] + minPath(row+1, col, grid, maxRow, dp);
        int way3 = grid[row][col] + minPath(row+1, col+1, grid, maxRow, dp);
        
        return dp[row][col] = min(way1, min(way2, way3));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        
        vector<vector<int>> dp(m, vector<int> (m, -1));
        
        int minimum = INT_MAX;
        for(int i=0; i<m; i++){           
            minimum = min(minimum, minPath(0, i, matrix, m-1, dp));
        }
         
        return minimum;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation Approach
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        
        vector<vector<int>> dp(m, vector<int> (m, 0));
        //Base cases
        for(int i=0; i<m; i++){
            dp[m-1][i] = matrix[m-1][i];
        }
        
        for(int i=m-2; i>=0; i--){
            //These default numbers will be used when it will hit invalid index
            //We don't want to consider that path
            //Since, we require minimum -> we give default values as large numbers
            int way1 = 1e6;
            int way3 = 1e6;
            for(int j=m-1; j>=0; j--){
                if(j > 0) way1 = matrix[i][j] + dp[i+1][j-1];
                int way2 = matrix[i][j] + dp[i+1][j];
                if(j < m-1) way3 = matrix[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(way1, min(way2, way3));
            }
        }
        
        int minimum = 1e7;
        for(int i=0; i<m; i++){
            minimum = min(minimum, dp[0][i]);
        }
        
        return minimum;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/