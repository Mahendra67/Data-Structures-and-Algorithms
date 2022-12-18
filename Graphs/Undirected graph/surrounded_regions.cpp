#include<iostream>
#include<bits/stdc++.h>
//Surrounded regions 130 Leetcode
/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        queue<pair<int,int>> q;
        //Any 'O' touching with boundary will not change
        
        //Mark the cells connected to boundary cells both having 'O' as visited
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //Boundary row and col
                if(i==0 || j==0 || i==row-1 || j==col-1){
                    if(board[i][j]=='O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            int p_row[] = {-1,0,1,0};
            int p_col[] = {0,1,0,-1};
            
            for(int k=0; k<4; k++){
                int fr = r + p_row[k];
                int fc = c + p_col[k];
                
                if(fr>=0 && fr<row && fc>=0 && fc<col && !vis[fr][fc]){
                    if(board[fr][fc]=='O'){
                        vis[fr][fc] = 1;
                        q.push({fr,fc});
                    }
                }
            }
        }
        
        //Now, change the unvisited 'O' to 'X'
        /*Only those 'O' will be unvisited which aren't connected to boundary 'O*/
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};

int main(){
    
    return 0;
}