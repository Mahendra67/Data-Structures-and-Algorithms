#include<iostream>
#include<bits/stdc++.h>
//Unique Paths Leetcode 980

/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every 
non-obstacle square exactly once.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
You have to travel *every non-obstacle square* exactly once
*/
class Solution {
public:    
    int ways(int cr, int cc, vector<vector<int>>& grid, vector<vector<int>>& vis, int emptyCell){
        //Base cases
        //Out of bound cases        
        if(cr == grid.size() || cc == grid[0].size()){
            return 0;
        }
        
        if(cr < 0 || cc < 0){
            return 0;
        }
        
        
        //If already visited, return 
        if(vis[cr][cc] == 1){
            return 0;
        }
        
        //If obstacle return
        if(grid[cr][cc] == -1){
            return 0;
        }
        
        //Check if you explored all empty squares
        //Also check if you are now standing at end cell
        if(emptyCell == 0 && grid[cr][cc] == 2){
            return 1;
        }
        
        //If you still have empty squares to explore but you reached end cell
        if(grid[cr][cc] == 2){
            return 0;
        }
        
        //else visit that grid, and decrease the no. of empty squares left to explore
        vis[cr][cc] = 1;
        //Only decrease the no. of empty square if it is grid[i][j] = 0
        //If we don't apply this condition: it will also decrease at starting cell
        if(grid[cr][cc]  == 0){
            emptyCell--;
        }
        
        //Explore all paths
        //Go right
        int way1 = ways(cr, cc+1, grid, vis, emptyCell);
        
        //Go left
        int way2 = ways(cr, cc-1, grid, vis, emptyCell);
        
        //Go top 
        int way3 = ways(cr-1, cc, grid, vis, emptyCell);
        
        //Go down
        int way4 = ways(cr+1, cc, grid, vis, emptyCell);
        
        
        //If you are done with your calls for that current grid, unvisit that grid
        //And increase no. of empty squares left to explore
        vis[cr][cc] = 0;
        
        return way1+way2+way3+way4;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        //First we need to find the starting point or ending point
        int m = grid.size();
        int n = grid[0].size();
        
        //Since, it can go in all 4 directions, we need to use a visited grid, or else it will get stuck in loop
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        //Starting cell
        int sr, sc;
        //Since we need to visit every non-obstacle square in that grid to reach end cell, keep track of number of 
        //empty cells. So, when you visit a cell, just decrease the no. of non-obstacle squares that are left to visit. 
        int emptyCell = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }else if(grid[i][j] == 0){
                    emptyCell++;
                }
            }
        }
        
        //Now, we now the starting or ending cell, explore all paths from any start or end cell
        return ways(sr, sc, grid, vis, emptyCell);
        
    }
};

/*-----------------------------------------------------------------------------------------------------------*/