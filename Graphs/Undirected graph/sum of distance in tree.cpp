#include<iostream>
#include<bits/stdc++.h>
//Sum of distances in tree Leetcode 834

/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there
is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith 
node in the tree and all other nodes.
*/


using namespace std;

/*-------------------------------------------------------------------------------------------------------------*/
//BRUTE FORCE APPROACH
class Solution {
public:
    //Finding distance b/w a node and src node using relaxation of edges
    int dist(vector<vector<int>> adj, int src){
        int n = adj.size();
        //Make a distance vector
        vector<int> dist(n,1e5);
        
        //BFS
        queue<int> q;
        
        dist[src] = 0;
        
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                /*In BFS (in unit weighted graphs), when you visit a node for the first
                time, it will be the shortest path*/
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    //Only push to the queue if you find a smaller path
                    //(this prevents infinite looping)
                    q.push(it);
                }
            }
        }
        
        //Since it is given that the tree is connceted, no need to check for unreachable node(since every node is connected)
        
        //Find out the sum of the distances
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += dist[i];
        }
        
        return sum;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        //Form an adjacency list
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> totalSumFromSrc(n);
        
        for(int i=0; i<n; i++){
            //Find the distance of each node from src node
            //src = i;
            totalSumFromSrc[i] = dist(adj, i);
        }
        
        return totalSumFromSrc;
    }
};

/*-------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------*/
//Optimization using DP 

int main(){
    
    return 0;
}