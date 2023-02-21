#include<iostream>
#include<bits/stdc++.h>
//Shortest path with Alternating Color Leetcode 1129

/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. 
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x 
such that the edge colors alternate along the path, or -1 if such a path does not exist.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Approach 1 : Using 2 visited vector for each node
/*
A node can be visited using only 2 possibilities : Red and Blue.

Apply a BFS traversal: Since edges are not weighted -> if you reach a node for the first time, it will be the shortest path
from the src node.

Push all the edges of src node as every edgeColor path is valid for it. (Since it is starting node, any path can be chosen).
Once, you reach a node which has not been visited yet, update it minDist[node] value.

Only push to the queue if and only if that node has not been visited by that pathColor before (use that visited array concept)
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //First make the adjacency list for both redEdges and blueEdges
        vector<vector<int>> redAdj(n);
        vector<vector<int>> blueAdj(n);
        
        for(auto &it: redEdges){
            int startNode = it[0];
            int endNode = it[1];
            
            redAdj[startNode].push_back(endNode);
        }
        
        for(auto &it: blueEdges){
            int startNode = it[0];
            int endNode = it[1];
            
            blueAdj[startNode].push_back(endNode);
        }
        
        //Since, the edges are not weighted, traversing using BFS will make sure that once we reach a node, it is going to be the shortest path
        vector<int> minDist(n, -1);
        
        //Pair would store 3 info: node number, distance from zero, edgeColor
        //N     :       No color
        //R     :       Red edge color
        //B     :       Blue edge color
        queue<pair<int,pair<int,char>>> q;
        
        //Push the first node into the queue
        q.push({0, {0, 'N'}});
        //Mark the distance of zero to itself as zero
        minDist[0] = 0;
        
        /*
        2 possiblities to visit a node: Either by red, or by blue path.
        Keep 2 visited array: visRed, and visBlue.
        visRed[node] = true means that node has been visited using Red path
        */
        
        vector<bool> visRed(n, false);
        vector<bool> visBlue(n, false);
        
        //Mark 0th node as visited 
        visRed[0] = true;
        visBlue[0] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second.first;
            char edgeCol = q.front().second.second;
            q.pop();
            
            /*
            If it is starting node, you have to search in both the adjList and 
            push each edge into the queue
            */
            
            //Mark the current node visited for edge used 
            
            //Only push to the queue if you find alternate color
            if(edgeCol == 'R'){
                visRed[node] = true;
                
                for(auto &it: blueAdj[node]){
                    int adjNode = it;
                    
                    //Only update the distance if you reach the node first time
                    if(minDist[adjNode] == -1){
                        minDist[adjNode] = dist + 1;
                    }
                    
                    //Only push if the adjacent node is not visited using blue path
                    if(visBlue[adjNode] == false){
                        q.push({adjNode, {dist+1, 'B'}});
                    }
                }
            }
            
            if(edgeCol == 'B'){
                visBlue[node] = true;
                
                for(auto &it: redAdj[node]){
                    int adjNode = it;
                    
                    //Only update the distance if you reach the node first time
                    if(minDist[adjNode] == -1){
                        minDist[adjNode] = dist + 1;
                    }
                    
                    //Only push the node if it is not visited using Red path
                    if(visRed[adjNode] == false){
                        q.push({adjNode, {dist+1, 'R'}});
                    }
                }
            }
            
            //In case of starting node, you have to search in both adjList and push every edge into queue
            else if(edgeCol == 'N'){
                for(auto &adjNode: redAdj[0]){
                    if(minDist[adjNode] == -1){
                        minDist[adjNode] = dist + 1;
                    }
                    q.push({adjNode,{dist+1, 'R'}});
                }
                
                for(auto &adjNode: blueAdj[0]){
                    if(minDist[adjNode] == -1){
                        minDist[adjNode] = dist + 1;
                    }
                    q.push({adjNode, {dist+1, 'B'}});
                }
            }
        }
        
        return minDist;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Same approach but made the code concise

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //First make the adjacency list for both redEdges and blueEdges
        //0th row is for redEdges
        //1th row is for blueEdges
        vector<vector<vector<int>>> adj(2, vector<vector<int>> (n, vector<int> (n, -1)));
        
        //To remove the initialized values (-1)
        for(int i=0; i<n; i++){
            adj[0][i].clear();
            adj[1][i].clear();
        }
        
        
        for(auto &it: redEdges){
            int startNode = it[0];
            int endNode = it[1];
            
            adj[0][startNode].push_back(endNode);
        }
        
        for(auto &it: blueEdges){
            int startNode = it[0];
            int endNode = it[1];
            
            adj[1][startNode].push_back(endNode);
        }
        
        vector<int> minDist(n, -1);
        
        queue<vector<int>> q;
        /*
        0   :   no color
        1   :   red
        2   :   blue
        */
        q.push({0,0,0});
        q.push({0,0,1});
        minDist[0] = 0;
        
        //2 visited array for both the colors
        vector<vector<int>> vis(2, vector<int> (n, 0)); 
        
        //Mark 0th node as visited 
        vis[0][0] = true;
        vis[1][0] = true;
        
        while(!q.empty()){
            auto nodeInfo = q.front();
            int node =  nodeInfo[0];
            int dist = nodeInfo[1];
            int edgeCol = nodeInfo[2];
            q.pop();
            
            vis[edgeCol][node] = 1;
            
            for(auto &it: adj[!edgeCol][node]){
                int adjNode = it;
                
                if(minDist[adjNode] == -1){
                    minDist[adjNode] = dist+1;
                }
                
                if(vis[!edgeCol][adjNode] == 0){
                    q.push({adjNode, dist+1, !edgeCol});
                }
            }
        }
        
        return minDist;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/