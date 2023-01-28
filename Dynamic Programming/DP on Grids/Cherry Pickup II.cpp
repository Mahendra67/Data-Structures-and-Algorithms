#include<iostream>
#include<bits/stdc++.h>
//Cherry Pickup II Leetcode 1463

/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of 
cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization approach
/*
Both the robots start at same row and move 1 step simultaneously -> hence row number will be same/common for traversals.

For each move of robot1 -> robot2 can move 3 different ways.
Hence, total 9 combinations of moves.
*/
class Solution {
public:
    int maxPath(int row,int colRobo1, int colRobo2, vector<vector<int>>& grid,
               int maxRow, int maxCol, vector<vector<vector<int>>>& dp){
        //Out of bound cases
        if(row > maxRow || colRobo1 > maxCol || colRobo2 > maxCol || colRobo1 < 0 || 
          colRobo2 < 0){
            return -1e7;
        }
        
        //Base case: Reaches last row
        /*
        2 cases: If both reaches same cell -> only one will pick up.
                If both reach diff cell -> both will pick up their own cell cherries.
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
        
        
        //9 different ways to move
        
        //Change in column no. is only -1 or 0 or 1
        int changeCol[] = {-1, 0, 1};
        
        int maxi = -1e9;
        //For robot1 : 3 ways to move
        for(int i=0; i<3; i++){
            //For robot2 : 3 ways to move
            for(int j=0; j<3; j++){
                //Check if they both reach same cell
                if(colRobo1 == colRobo2){
                    //New column no. = currentColNo. + changeCol[i]  -> for robo1
                    //Only add cherries of current cell 1 time
                    maxi = max(maxi, grid[row][colRobo1] + 
                            maxPath(row+1, colRobo1 + changeCol[i], colRobo2 + changeCol[j],
                                    grid, maxRow, maxCol, dp));
                }else{
                    maxi = max(maxi, grid[row][colRobo1] + grid[row][colRobo2] + 
                            maxPath(row+1, colRobo1 + changeCol[i], colRobo2 + changeCol[j],
                                   grid, maxRow, maxCol, dp));
                }
            }
        }
        
        return dp[row][colRobo1][colRobo2] = maxi;   
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        /*
        In recursion tree, row can have values from 0 to n-1. (n values)
        colRobo1 can have values from 0 to m-1. (m values)
        colRobo2 can have values from 0 to m-1. (m values)
        Hence, dp array of size (n*m*m) is needed
        */
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        //Robot1 starts from (0,0)
        //Robot2 starts from (0, n-1) -> n is no. of columns
        return maxPath(0, 0, m-1, grid, n-1, m-1, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation Approach
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));
        
        //Base cases: When it reaches last row (from recursion)
        //colRobo1 can have values from 0 to m-1, colRobo2 can have values from 0 to m-1
        //row will be fixed = n - 1;  (last row)
        for(int colRobo1=0; colRobo1<m; colRobo1++){
            for(int colRobo2=0; colRobo2<m; colRobo2++){
                if(colRobo1 == colRobo2){
                    //Only store once
                    dp[n-1][colRobo1][colRobo2] = grid[n-1][colRobo1];
                }else{
                    dp[n-1][colRobo1][colRobo2] = grid[n-1][colRobo1] + 
                                                        grid[n-1][colRobo2];
                }
            }
        }
        
        
        //In recursion, we went from ROW->0 to ROW->n-1  (n is no. of rows)
        //In tabulation, we will go from n-1 to 0th row (n-1 th row is already filled: base case)
        for(int row = n-2; row>=0; row--){
            //Inner loops can be from 0 to n OR n to 0 (doesnt matter)
            for(int colR1=0; colR1<m; colR1++){
                for(int colR2=0; colR2<m; colR2++){
                    /*----------------------------------LINES FROM RECURSION SOLUTION-----------------------------------------------*/
                    //9 different ways to move

                    //Change in column no. is only -1 or 0 or 1
                    int changeCol[] = {-1, 0, 1};

                    int maxi = -1e9;
                    //For robot1 : 3 ways to move
                    for(int i=0; i<3; i++){
                        //For robot2 : 3 ways to move
                        for(int j=0; j<3; j++){
                            //Check if they both reach same cell
                            
                            //Make sure to check for OUT OF BOUNDS condition
                            //m-1 is the maxCol Index
                            if(colR1+changeCol[i] >= m || colR1+changeCol[i] < 0 || colR2+changeCol[j] >= m || colR2+changeCol[j] < 0){
                                continue;
                            }
                            
                            if(colR1 == colR2){
                                //New column no. = currentColNo. + changeCol[i]  -> for robo1
                                //Only add cherries of current cell 1 time
                                maxi = max(maxi, grid[row][colR1] + dp[row+1][colR1+changeCol[i]][colR2+changeCol[j]]);
                            }else{
                                maxi = max(maxi, grid[row][colR1] + grid[row][colR2] + dp[row+1][colR1+changeCol[i]][colR2+changeCol[j]]);
                            }
                        }
                    }
                    /*----------------------------------LINES FROM RECURSION SOLUTION-----------------------------------------------*/
                    
                    dp[row][colR1][colR2] = maxi;
                }
            }
        }
        
        //Starting pos
        //dp[row][starting colIndex of ROBOT1][starting colIndex of Robot2]
        return dp[0][0][m-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/