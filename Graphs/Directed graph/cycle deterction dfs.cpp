#include<iostream>
#include<bits/stdc++.h>
//Detect a loop in a directed graph : DFS
using namespace std;
/*
The approach that worked in undirected graph wont work for directed graph.

Approach for directed graph:
If you find a node that is visited on the same path, then loop exists.

*/

class Solution {
  public:
  
    bool dfs(vector<int>& vis, vector<int>& pathVis, vector<int> adj[], int node){
        vis[node] = 1;
        //Since we are considering the current node in the path, mark pathVis as visited
        pathVis[node] = 1;
        
        //Traverse through its neighbouring nodes
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(vis, pathVis, adj, it)==true){
                    return true;
                }
            }else if(vis[it]==1 && pathVis[it]==1){
                //The node is already visited and lies in current path as it is also pathVisited
                return true;
            }
        }
        
        //It didn't found any loop, hence going back
        //Remove the current node from path, since we are going back and not considering it in path.
        pathVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        //2 vectors : 1 to keep track of visited nodes and other to keep track of current path nodes
        
        vector<int> vis(V,0);
        
        vector<int> pathVis(V,0);
        
        //Traverse through all visited nodes
        for(int i=0; i<V; i++){
            if(!vis[i]){
                //i is starting node
                if(dfs(vis, pathVis, adj, i)==true){
                    return true;
                }
            }
        }
        return false;
    }
};



int main(){
    
    return 0;
}