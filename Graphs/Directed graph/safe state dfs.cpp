#include<iostream>
#include<bits/stdc++.h>
//Find eventual safe states Leetcode 802
/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array 
of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible
 path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
using namespace std;
/*
If any node that is connected to a cycle via a path, it is not a safe node.
Nodes in a cycle are also not a safe node, since it is mentioned every path from a safe 
node should end at terminal node.

Also, a terminal node is also a safe node.
*/


//CYCLE DETECTION APPROACH: DFS (gives TLE)
class Solution {
public:
    //Cycle detection approach
    bool dfs(vector<vector<int>> graph, vector<int>& vis, vector<int>& pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(graph, vis, pathVis, it)==true){
                    return true;
                }
            }else if(pathVis[it]){
                //already visited and also in the same path
                return true;
            }
        }
        
        /*If you reach here, that means no cycle detected till current node.
        hence, going back to prev recursive call, 
        we dont want this node to consider in this path*/
        
        /*
        If a graph has a cycle, then it would not reach here, 
        it will return true in above condition, hence for any node 
        that is connected to a cycle, the pathVis for that node will be 1. 
        */
        pathVis[node] = 0;
        
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        
        vector<int> safeNode;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int start = i;
                dfs(graph, vis, pathVis, start);
            }
        }
        
        /*
        Safe nodes will be the nodes which have pathVis as 0.
        */
        
        for(int i=0; i<n; i++){
            if(!pathVis[i]){
                safeNode.emplace_back(i);
            }
        }
        
        return safeNode;
    }
};



int main(){
    
    return 0;
}