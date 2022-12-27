#include<iostream>
#include<bits/stdc++.h>
//Bellman-Ford Algorithm (Single source shortest path)
/*Time Complexity : O(VE)
where V is no. of vertices and E is the no. of edges
Time Complexity is worse than Dijktra Algorithm*/
/*
Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance 
of all the vertex's from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.
*/
using namespace std;

/*  
Dijktra Algorithm fails for graph with negative edges and negative weight cycles.

Bellman ford algorithm is applicable only in Directed graphs. In case, you want it to work for undirected
graph, you have to represent every edge as bidirectional edge.

Bellman ford algorithm helps to detect negative weight cycles.
*/

/*
Bellman-Ford Algorithm : 
Take a distance matrix and initialize the src node as 0. Now, relax all edges n-1 times sequentially.
Here, n is the no. of vertices.
*/

//DETECT NEGATIVE WEIGHT CYCLE
/*
To detect negative weight cycles using Bellman-Ford Algorithm :
Relax all edges n-1 times sequentially. According to Bellman-Ford Algorithm after relaxing all edges n-1 
times, the updated distance array should have the smallest path from the src node.

Relax all edges one more time, if you still find a shorter distance, then that means the graph contains a
negative weight cycles.
*/

/*-----------------------------------------------------------------------------------------------------------*/

class Solution {
  public:
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        //V = n = no. of vertices
        vector<int> dist(V,INT_MAX);
        
        //Dist to src node is 0
        dist[S] = 0;
        
        //Relax all edges n-1 times 
        for(int i=0; i<V-1; i++){
            //Traverse in all possible paths
            for(auto it: edges){
                //u -> v
                int u = it[0];
                int v = it[1];
                int weight = it[2];
                
                //Relax all edges that are possible
                //dist[v] can be relaxed only if dist[u] is known -> check if dist[u] != 1e8
                if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        //Since negative cycles are also given
        //Relax one more time to check if it still gives another shortest path
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                //Path is still decreasing even after n-1 iterations
                //Negative weight cycle exists
                return {-1};
            }
        }
        
        return dist;
        
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}