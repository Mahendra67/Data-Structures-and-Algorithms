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
All terminal nodes will be safe nodes.

Terminal nodes are nodes which have outdegree = 0;
In topo sort, we worked with indegree of nodes.

Approach : Reverse the edges between nodes. Now, we can say that terminal nodes are nodes
which have indegree = 0 (Since all edges were reversed.)
The traversal then starts from terminal nodes.

*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<int> ans;
        
        //1. Reverse the graph;
        vector<vector<int>> revAdj(n);
        //Create Reverse adjacency list
        for(int i=0 ;i<n ;i++){
            //a->b to b->a
            for(auto it: graph[i]){
                revAdj[it].push_back(i);
                
                //TO AVOID ONE MORE 2 nested loop for calculating indegree
                /*
                Since we are reversing the graph edges, the outdegree of previous 
                graph will become indegree of reversed graph.
                To calculate outdegree, we can count the no. of nodes in each adj[node]
                */
                
                indegree[i]++;
            }
            /*Another way to calculate outdegree of previous graph
            indegree[i] = graph[i].size();
            */
        }
        
        // To calculate indegree
        // for(int i=0; i<n; i++){
        //     for(auto it: revAdj[i]){
        //         indegree[it]++;
        //     }
        // }
        
        //Normal TOPO SORT (Kahn Algorithm)
        queue<int> q;
        for(int i=0 ; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        //Since we need it in ascending order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


int main(){
    
    return 0;
}