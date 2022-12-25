#include<iostream>
#include<bits/stdc++.h>
//Cheapest flights within k stops LeetCode 787
/*
There are n cities connected by some number of flights. You are given an array flights 
where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi 
to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to 
dst with at most k stops. If there is no such route, return -1.
*/
using namespace std;

/*------------------------------------------------------------------------------------------------------*/
//Modified Dijktras Algorithm 
/*
Instead of using Priority Queue, we use queue instead.
Priority queue is not used here because it gives the minimum cost b/w 2 nodes.
And It is not necessary that minimum cost path path will pass within k stops. (It can be more than k stops)
*/
class Solution {
public:
    //Given k is for inbetween stops, and if we consider end as a stop, k+
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Create an adjacency list
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> minCost(n, INT_MAX);
        
        queue<pair<int,pair<int,int>>> q;
        
        //Push the src node into it
        //Pair{curr_min_dist_to_reach_node, node, steps}
        q.push({0, {src, 0}});
        minCost[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            int cost = it.first;
            int node = it.second.first;
            int steps = it.second.second;
            q.pop();
            
            //If either we finish our steps or we reach destination node, do nothing.
            //Let it run other iteration remaining in queue in case it finds cheaper path
            if(steps == k+1 || node == dst){
                continue;
            }
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjCost = it.second;
                
                if(cost + adjCost < minCost[adjNode]){
                    minCost[adjNode] = cost + adjCost;
                    
                    //Push with increased steps
                    q.push({minCost[adjNode], {adjNode, steps+1}});
                }
            }
        }
        
        //If unreachable return -1, else return the cheapest path
        return (minCost[dst]==INT_MAX) ? -1 : minCost[dst]; 
    }
};

/*------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}