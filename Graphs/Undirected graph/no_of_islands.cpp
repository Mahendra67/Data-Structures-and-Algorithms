#include<iostream>
#include<bits/stdc++.h>
//No. of islands LEETCODE 200
/*
Given an m x n 2D binary grid grid which represents 
a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/
using namespace std;

//DFS APPROACH
//Same approach as no. of provinces but here, instead of giving adjacency matrix (1D relation: connected nodes were in row of current node) , 
//map of nodes (grid) is given (2D relation: row and col)
class Solution {
public:
    void helper(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        //We can't use row/col to check boundary condition as it gets updated each call
        //Hence calculate the max row, and max col
        int r = grid.size();
        int c = grid[0].size();
        
        //Mark it as visited
        vis[row][col] = '1';      
        
        //Surrounding node indexes can be
        int s_row[] = {-1,0,1,0};
        int s_col[] = {0,1,0,-1};
        
        for(int k=0; k<4; k++){
            //Check if the index is within limits
            //Also, check if the node is visited or not
            //Check if it is land
    
            int final_row = row + s_row[k];
            int final_col = col + s_col[k];
            
            
            if(final_row >= 0 && final_row < r && final_col >=0 && final_col < c
              && !vis[final_row][final_col] && grid[final_row][final_col] == '1'){
                
                //Recursive call to neighbours
                helper(grid, vis, final_row, final_col);
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        
        //Make another mxn matrix to store visited 
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //Make sure this runs when it is land
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    helper(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};

int main(){
    
    return 0;
}