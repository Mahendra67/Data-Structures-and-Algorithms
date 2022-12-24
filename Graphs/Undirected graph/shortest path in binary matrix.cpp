#include<iostream>
#include<bits/stdc++.h>
//Shortest path in a Binary Matrix LeetCode 1091
/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Optimized Approach : Dijktras Algo with Queue

class Solution {
public:
    //Using QUEUE
    /*
    Since it is unit weighted undirected graph, it can be solved using queue data structure.
    (Since by travelling any path, it will increase by 1. No shorter edge weight, as every
    path is equal).
    
    In this case, by using queue instead of priority queue, we eliminate logN for insertion.
    (PQ takes logN to perform insertion)
    */
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Edge case : If src node is 1
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        
        pair<int,int> src = {0,0};
        // pair<int,int> des = {n-1,n-1};
        
        //Dijktra
        queue<pair<int,pair<int,int>>> q;
        
        //min dist vector of vector
        vector<vector<int>> minCells(n,vector<int> (n,INT_MAX));
        
        //Pair : {dist,{row, col}}
        q.push({1,src});
        //Update minCells of src node to 1
        minCells[0][0] = 1;
        
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            
            //For its neighbours
            int possible_row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int possible_col[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            
            for(int i=0; i<8; i++){
                int fr = r + possible_row[i];
                int fc = c + possible_col[i];
                
                //Check if it is valid index
                if(fr>=0 && fr<n && fc>=0 && fc<n && grid[fr][fc]==0){
                    //Since path weight between 2 nodes is 1
                    if(dis + 1 < minCells[fr][fc]){
                        minCells[fr][fc] = dis + 1;
                        
                        q.push({minCells[fr][fc], {fr,fc}});
                    }
                }
            }
        }
        
        //If minCells[n-1][n-1] is unreachable, return -1
        if(minCells[n-1][n-1] == INT_MAX){
            return -1;
        }
        
        return minCells[n-1][n-1];
    }
};


/*---------------------------------------------------------------------------------------------------------------------------------*/

//Approach using Dijktra Algorithm
/*Intuition: Since the problem has something to do with negihbouring nodes -> graph problem
Also, since it requires the shortest distance from src to des node -> Dijktra Algorithm*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Edge case : If src node is 1
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        
        pair<int,int> src = {0,0};
        // pair<int,int> des = {n-1,n-1};
        
        //Dijktra
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        
        //min dist vector of vector
        vector<vector<int>> minCells(n,vector<int> (n,INT_MAX));
        
        //Pair : {dist,{row, col}}
        pq.push({1,src});
        //Update minCells of src node to 1
        minCells[0][0] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            
            //For its neighbours
            int possible_row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int possible_col[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            
            for(int i=0; i<8; i++){
                int fr = r + possible_row[i];
                int fc = c + possible_col[i];
                
                //Check if it is valid index
                if(fr>=0 && fr<n && fc>=0 && fc<n && grid[fr][fc]==0){
                    //Since path weight between 2 nodes is 1
                    if(dis + 1 < minCells[fr][fc]){
                        minCells[fr][fc] = dis + 1;
                        
                        pq.push({minCells[fr][fc], {fr,fc}});
                    }
                }
            }
        }
        
        //If minCells[n-1][n-1] is unreachable, return -1
        if(minCells[n-1][n-1] == INT_MAX){
            return -1;
        }
        
        return minCells[n-1][n-1];
    }
};

/*---------------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    //USING SET 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Edge case : If src node is 1
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        
        pair<int,int> src = {0,0};
        // pair<int,int> des = {n-1,n-1};
        
        //Dijktra using SET
        set<pair<int,pair<int,int>>> s;
        
        //min dist vector of vector
        vector<vector<int>> minCells(n,vector<int> (n,INT_MAX));
        
        //Pair : {dist,{row, col}}
        s.insert({1,{0,0}});
        //Update minCells of src node to 1
        minCells[0][0] = 1;
        
        while(!s.empty()){
            auto it = *(s.begin());
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            s.erase(it);
            
            //For its neighbours
            int possible_row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int possible_col[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            
            for(int i=0; i<8; i++){
                int fr = r + possible_row[i];
                int fc = c + possible_col[i];
                
                //Check if it is valid index
                if(fr>=0 && fr<n && fc>=0 && fc<n && grid[fr][fc]==0){
                    //Since path weight between 2 nodes is 1
                    if(dis + 1 < minCells[fr][fc]){
                        //Check if the minCells is already relaxed
                        if(minCells[fr][fc] != INT_MAX){
                            s.erase({minCells[fr][fc], {fr,fc}});
                        }
                        
                        minCells[fr][fc] = dis + 1;
                        s.insert({minCells[fr][fc], {fr,fc}});
                    }
                }
            }
        }
        
        //If minCells[n-1][n-1] is unreachable, return -1
        if(minCells[n-1][n-1] == INT_MAX){
            return -1;
        }
        
        return minCells[n-1][n-1];
    }
};

/*---------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}