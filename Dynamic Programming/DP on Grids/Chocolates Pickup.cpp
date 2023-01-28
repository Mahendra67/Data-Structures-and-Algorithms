#include<iostream>
#include<bits/stdc++.h>
//Chocolates Pickup GFG 3D Dp problem

/*
You are given an r rows and c cols matrix grid representing a field of cherries where grid[i][j] 
represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization 
class Solution {
  public:
  //Fixed starting point, BUT variable ending point. (2 starting point)
  /*
  At each step, both increase their row number by 1. And since they start from same row, the row number will
  be common.
  */
  //Starting from fixed starting point
  //But we are checking all paths of robo1 and robo2 simultanouesly
    int maxChoco(int row, int colRobo1, int colRobo2, int maxRow, int maxCol, vector<vector<int>>& grid,
                vector<vector<vector<int>>>& dp){
        //Out of bound cases
        if(colRobo1 > maxCol || colRobo1 < 0 || colRobo2 > maxCol || colRobo2 < 0){
            return -1e6;
        }
        
        //Base cases
        /*
        2 cases: Either both robots reach the same cell or they reach different cell.
        If they reach same cell, only 1 can pick the chocolates.
        If they reach diff cell, both can pick their own chocolates
        */
        if(row == maxRow){
            if(colRobo1 == colRobo2){
                return grid[row][colRobo1];
            }else{
                return grid[row][colRobo1] + grid[row][colRobo2];
            }
        }
        
        
        if(dp[row][colRobo1][colRobo2] != -1){
            return dp[row][colRobo1][colRobo2];
        }
        
        /*
        For every move of robot1, -> robot2 can move in 3 different ways.
        Total 9 combination of moves
        */
        
        //Change in columns
        int dc[] = {-1, 0, 1};
        
        int maxi = 0;
        
        //Moves for robot1: Change in col no. for robo1 (i)
        for(int i=0; i<3; i++){
            //Moves for robot2: Change in col no. for robo2 (j)
            for(int j=0; j<3; j++){
                //Same 2 cases as above
                //If they reach same cell, consider only one time
                if(colRobo1 == colRobo2){
                    //New column no. for robot1 = colRobo1 + dc[i]
                    //New column no. for robot2 = colRobo2 + dc[j]
                    maxi = max(maxi, grid[row][colRobo1] + maxChoco(row+1, colRobo1+dc[i], colRobo2+dc[j],
                                maxRow, maxCol, grid, dp));
                }else{
                    maxi = max(maxi, grid[row][colRobo1] + grid[row][colRobo2] + maxChoco(row+1, 
                                colRobo1+dc[i], colRobo2+dc[j], maxRow, maxCol, grid, dp));
                }
            }
        }
        
        return dp[row][colRobo1][colRobo2] = maxi;
    }
  
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        //In recursion, row can have values from 0 to n-1.  (n is no. of row)
        //colRobo1 can have values from 0 to m-1. (m is no. of col)
        //colRobo2 can have values from 0 to m-1. (m is no. of col).   -> Hence, dp 3d array of n*m*m
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        //Robo1 starts from 0th col, Robo2 starts from (m-1)th col
        return maxChoco(0, 0, m-1, n-1, m-1, grid, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/