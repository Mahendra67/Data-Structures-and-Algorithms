#include<iostream>
#include<bits/stdc++.h>
//Rotten Oranges Leetcode 994
/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
using namespace std;

//BFS TRAVERSAL
class Solution {
public:
    int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        //Since oranges rot at same time of 1 node distance, 
        //we will use bfs traversals
        int row = grid.size();
        int col = grid[0].size();
        
        //In queue, we will store pair of (row_index, column_index), time
        // {{row,col},time}
        
        queue<pair<pair<int,int>,int>> q;
        
        //visited array
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        //Push initial rotten oranges into the queue
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    //At start, time=0
                    q.push({{i,j},0});
                    //mark them visited
                    vis[i][j] = 2;
                }
            }
        }
        
        int time = 0; 
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            int possible_row[] = {-1,0,1,0};
            int possible_col[] = {0,1,0,-1};
            
            time = max(time,t);
            
            //Atmost 4 neighbours
            for(int i=0; i<4; i++){
                int fr = r + possible_row[i];
                int fc = c + possible_col[i];
                
                if(fr>=0 && fr<row && fc>=0 && fc<col 
                  && vis[fr][fc]!=2 && grid[fr][fc]==1){
                    q.push({{fr,fc},t+1});
                    vis[fr][fc] == 2;
                }
            }
        }
        
        //Check if some oranges are left/not rotten
        for(int i = 0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return time;
    }
};


//Similar approach, but we keep track of no. of oranges and no. of rotten oranges
class Solution {
public:
    int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        //Since oranges rot at same time of 1 node distance, 
        //we will use bfs traversals
        int row = grid.size();
        int col = grid[0].size();
        
        //In queue, we will store pair of (row_index, column_index)
        queue<pair<int,int>> q;
        
        //Count no. of oranges, also, keep a counter for rotten ones
        //At the end of program, if no. of rotten ones== no. of oranges, return minutes
        //else return -1 (not every orange rot)
        
        //Also, push all initial rotten oranges (tcount)
        int tcount = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]){
                    tcount++;
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }
                }
            }
        }
        //Edge case : No oranges 
        if(tcount==0){
            return 0;
        }
        
        
        int possible_row[] = {-1,0,1,0};
        int possible_col[] = {0,1,0,-1};
        
        int rottenCount = 0;
        int minutes = 0;
        
        while(!q.empty()){            
            //To count no. of rotten oranges
            int size = q.size();
            rottenCount += size;
            
            for(int i=0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                //Atmost 4 neighbours
                for(int i=0; i<4; i++){
                    int fr = r + possible_row[i];
                    int fc = c + possible_col[i];

                    if(fr>=0 && fr<row && fc>=0 && fc<col 
                      && grid[fr][fc]==1){
                        //Update into grid and push to queue
                        grid[fr][fc] = 2;
                        q.push({fr,fc});
                    }
                }
            }
            /*
            At last iteration, q becomes empty (when there are no more oranges that can rot).
            But the counter(minutes) increases in the last iteration too.
            Hence, we return decrement minutes by 1(only 1 time)
            */
            minutes++;
        }
        
        minutes -= 1;
        
        //If no. of oranges == no. of rotten oranges, return minutes else, -1
        if(tcount==rottenCount){
            return minutes;
        }else return -1;
    }
};



int main(){
    
    return 0;
}