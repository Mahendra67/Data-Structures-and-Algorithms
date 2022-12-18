#include<iostream>
#include<bits/stdc++.h>
// 1020 Leetcode (No. of enclaves) 
/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/
using namespace std;


//Approach : MultiSource BFS
class Solution {
public:
    int count_boundary_land = 0;
    
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        //Count no. of 1s
        int count1 = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    count1++;
                }
            }
        }
        
        //Start from the outer layer and apply dfs/bfs on those paths
        //upper row and lower row
        queue<pair<int,int>> q;
        
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                //first row, first col, last row, last col
                if(r==0 || c==0 || r==row-1 || c==col-1){
                    if(grid[r][c]==1){
                        q.push({r,c});
                        vis[r][c] = 1;
                    }
                }
            }
        }
        
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            //Increase boundary land counter
            count_boundary_land++;
            
            int p_row[] = {-1,0,1,0};
            int p_col[] = {0,1,0,-1};

            for(int k=0; k<4; k++){
                int fr = r + p_row[k];
                int fc = c + p_col[k];

                if(fr>=0 && fr<row && fc>=0 && fc<col && !vis[fr][fc] && grid[fr][fc]==1){
                    q.push({fr,fc});
                    vis[fr][fc] = 1;
                }
            }
        }
        
        return count1 - count_boundary_land;
    }
};




//Approach using DFS : gives TLE :(

class Solution {
public:
    void dfs(vector<vector<int>> grid, vector<vector<int>>& vis, int r, int c){
        int row = grid.size();
        int col = grid[0].size();
        
        vis[r][c] = 1;
        
        //Increase boundary land counter
        count_boundary_land++;
        
        int p_row[] = {-1,0,1,0};
        int p_col[] = {0,1,0,-1};
        
        for(int k=0; k<4; k++){
            int fr = r + p_row[k];
            int fc = c + p_col[k];
            
            if(fr>=0 && fr<row && fc>=0 && fc<col && !vis[fr][fc] && grid[fr][fc]==1){
                dfs(grid, vis, fr, fc);
            }
        }
        return;
    }
    
    int count_boundary_land = 0;
    
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        //Count no. of 1s
        int count1 = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    count1++;
                }
            }
        }
        
        //Start from the outer layer and apply dfs/bfs on those paths
        //upper row and lower row
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                //first row, first col, last row, last col
                if(r==0 || c==0 || r==row-1 || c==col-1){
                    if(grid[r][c]==1){
                        dfs(grid,vis,r,c);
                    }
                }
            }
        }
        
        return count1 - count_boundary_land;
    }
};



int main(){
    
    return 0;
}