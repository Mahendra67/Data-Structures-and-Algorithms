#include<iostream>
#include<bits/stdc++.h>
//Find if path exists in graph
/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes 
a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, 
and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source 
to destination, or false otherwise.
*/

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //Make the adj list with the given relations
        vector<vector<int>> adj(n);
        
        if(source == destination) return true;
        
        //Adding relations of nodes in graph
        for(auto it: edges){
            //Since it is undirected graph, add both relations
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //Start from source and check if you touch destination, if yes return true
        bool touched = false;
        
        //Using BFS Traversal
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                //Check if the adjacent node is destination node or not
                if(it == destination){
                    touched = true;
                    break;
                }else if(!vis[it]){
                    //If not a destination node push into queue
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return touched;
    }
};

int main(){
    
    return 0;
}