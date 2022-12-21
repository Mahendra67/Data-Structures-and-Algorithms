#include<iostream>
#include<bits/stdc++.h>
//Possible Bipartition LeetCode 886
/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that 
the person labeled ai does not like the person labeled bi, return true if it is possible 
to split everyone into two groups in this way.
*/

using namespace std;

/*In both DFS and BFS approaches, if the given graph can be coloured just by using 2 colors 
such that no adjacent nodes can have the same color, then bipartition is possible*/


//DFS Approach
class Solution {
public:
    //Same approach as check if the graph is bipartite
    bool dfs(vector<vector<int>> graph, vector<int>& vis, int node, int col, 
            vector<int>& color){
        color[node] = col;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                vis[it] = 1;
                if(dfs(graph, vis, it, !col, color)==false){
                    return false;
                }
            }else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //Since it is 1-based indexing
        vector<int> vis(n+1,0);
        vector<int> color(n+1);
        
        vector<vector<int>> graph(n+1);
        
        for(auto it: dislikes){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vis[i] = 1;
                int col = 0;
                if(dfs(graph, vis, i, col, color)==false){
                    return false;
                }
            }
        }
        
        return true;
    }
};



//BFS Approach
class Solution {
public:
    //Same approach as check if the graph is bipartite
    bool bfs(vector<vector<int>> graph, vector<int>& color, int start, vector<int>& vis){
        queue<int> q;

        q.push(start);
        //Mark the starting colour as 0
        color[start] = 0;
        vis[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(!vis[it]){
                    //Visit that node
                    vis[it] = 1;
                    color[it] = !color[node];
                    q.push(it);
                }else if(color[node] == color[it]){
                    //If adjacent node has same color return false
                    return false;
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //Since it is 1-based indexing
        vector<int> vis(n+1,0);
        vector<int> color(n+1);
        
        vector<vector<int>> graph(n+1);
        
        for(auto it: dislikes){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        //BFS
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                if(bfs(graph, color, i, vis) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    
    return 0;
}