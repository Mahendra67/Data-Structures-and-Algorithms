#include<iostream>
#include<bits/stdc++.h>
//Network Delay Time LeetCode 743

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as 
directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time 
it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive 
the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

using namespace std;

/*-------------------------------------------------------------------------------------------------------------*/

/*
Approach:
Use Dijktras Algorithm to find the smallest time from source node to each node.
Now, from the minimum time taken array, return the maximum time taken to reach a node from src node.
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //first construct the adj list
        //Since it is 1 based indexing, we have to declare array of size n+1
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto it: times){
            int node1 = it[0];
            int node2 = it[1];
            int wt = it[2];
            
            adj[it[0]].push_back({node2, wt});
        }
        
        
        //Apply dijktra's algorithm
        //Pair stores {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> minTime(n+1, INT_MAX);
        
        //Push src node in pq. Here, k is src node
        int src = k;
        minTime[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int time = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            for(auto it: adj[currNode]){
                int adjNode = it.first;
                int adjTime = it.second;
                
                //Relax the edges if you find smaller time to reach adjNode
                if(time + adjTime < minTime[adjNode]){
                    minTime[adjNode] = time + adjTime;
                    
                    pq.push({minTime[adjNode], adjNode});
                }
            }
        }
        
        /*Now, from the minTime taken to reach each node, return the maximum timeTaken to reach a node as that will be the max time needed to visit every node.*/
        
        int maxTime = INT_MIN;
        for(int i=1; i<n+1; i++){
            maxTime = max(maxTime, minTime[i]);
        }
        
        //If any node is unreachable, the maxTime should be INT_MAX (as you couldn't relax it)
        if(maxTime == INT_MAX){
            return -1;
        }
        
        return maxTime;
    }
};

/*-------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}