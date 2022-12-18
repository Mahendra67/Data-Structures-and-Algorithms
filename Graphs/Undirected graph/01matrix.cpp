#include<iostream>
#include<bits/stdc++.h>

//0/1 matrix Leetcode 542
/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

Find the distance of nearest 0 from each cell. If a cell itself is zero, distance would be 0.

The distance between two adjacent cells is 1.
*/
using namespace std;


//BFS Approach
/*
Since, we need the nearest 0 : looking at multiple paths at same time level wise (hence, bfs traversal)
*/
class Solution {
public:    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> ans(row,vector<int> (col,0));
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        queue<pair<pair<int,int>,int>> q;
        //{{row,col},distance}
        
        //Push the initial positions for BFS to start
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            //Update to ans
            //For all zero values in cell, the distance becomes zero
            ans[r][c] = distance;
            
            int p_row[] = {-1,0,1,0};
            int p_col[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int fr = r + p_row[i];
                int fc = c + p_col[i];
                
                if(fr>=0 && fr<row && fc>=0 && fc<col && !vis[fr][fc]){
                    //If it reaches here, means it found a non-zero
                    vis[fr][fc] = 1;
                    q.push({{fr,fc}, distance+1});
                }
            }
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}