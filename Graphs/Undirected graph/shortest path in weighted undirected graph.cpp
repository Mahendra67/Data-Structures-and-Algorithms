#include<iostream>
#include<bits/stdc++.h>
/*Shortest path in an weighted undirected graph GFG*/
/*
You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges 
describing there are edges between a to b with some weight, find the shortest path between the 
vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.
*/
using namespace std;

/*------------------------------------------------------------------------------------------------------------------------*/


class Solution {
  public:
    //Dijktra Algorithm to find shortest path but
    //a parent vector is used to keep track of parent node(to remember where it came from)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        //Create an adjaceny list
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        //Dijktra Algorithm
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n+1, INT_MAX);
        
        //Parent array to keep track of its parent node
        vector<int> parent(n+1);
        //At starting initialize it to its node index
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        
        //Push source node to pq (source is given as 1)
        //{edgeWt, node}
        int src = 1;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                
                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    
                    pq.push({dist[adjNode], adjNode});
                    //Keep track of parent if you find a shorter path
                    parent[adjNode] = node;
                }
            }
        }
        
        //In case the destination node (n) can't be reached
        if(dist[n] == INT_MAX){
            return {-1};
        }
        
        //To get the path, we have to traverse from destination node(n) and move backwards to its parent, and
        //then to its parent's parent until we reach 1 (src node)
        //Src node's parent would be itself only (since we intialized parent of a node to itself in starting)
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            //Update node to its parent (which is stored in parent[node])
            node = parent[node];
        }
        
        //If it reaches here means, parent[node] == node meaning we have reached src node.
        //But src node is not pushed to path
        path.push_back(node);
        
        //Since we traversed and pushed from 'n' node to src (1), the path obtained is in reverse.
        reverse(path.begin(), path.end());
        
        return path;
    }
};


/*-------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}