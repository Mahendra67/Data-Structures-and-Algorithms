#include<iostream>
#include<bits/stdc++.h>
//Shortest path in Undirected weighted graph from a source node GFG
/*
You are given an Undirected Graph having unit weight, 
Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, 
then return -1 for that vertex.
*/
using namespace std;

class Solution {
  public:
  /*
  Approach:
  Start from src node and do a bfs traversal.
  Maintain a dist[] which is initialized to infinity.
  In the bfs traversal, push {curr node, distance to reach from src node to curr node} into the queue.
  If (distCurrNode + weight) to reach the neighbouring node is smaller than what was stored in dist[], update it 
  and push to the queue. 
  
  Only push to the queue if you find smaller path. If you push all neighbouring nodes with their current 
  distance to reach that node (instead of pushing only if you find smaller path) -> this will only increase time
  complexity (and all the iterations for that node will never update the shortest path, as the path to reach 
  the current node was not the shortest path -> hence no need to push)
 
  
  Note: For unweighted graphs or weighted graphs with wt=1, apply normal BFS.
        In such graphs, when you visit a node for first time using BFS, it always will be shortest path.
        Also, no need to push pair of(node, shortest_dis[node]) into the queue. Just push the node
        
        for(auto it: adj[node]){
            if(dis[it]==INT_MAX){
                dis[it] = dis[node] + 1;
            }
        }
  */
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //Make the graph first
        vector<vector<int>> adj(N);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        //Shortest distance vector
        vector<int> dist(N, INT_MAX);
        
        //Normal BFS
        queue<pair<int,int>> q;
        
        //Source can be other than 0th node
        dist[src] = 0;
        q.push({src, dist[src]});
        
        while(!q.empty()){
            int node = q.front().first;
            //Wt is the distance it took to reach node from src node
            int wt = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                //Distance to reach neigbouring node from node (1 in this case)
                int w = 1;
                //If you find a smaller path, update in dist
                if( wt + w < dist[it]){
                    dist[it] = wt + w;
                    q.push({it, dist[it]});
                }
            }
        }
        
        //Check if any nodes were unreachable from src node
        for(int i=0; i<N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

int main(){
    
    return 0;
}