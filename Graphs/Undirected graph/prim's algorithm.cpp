#include<iostream>
#include<bits/stdc++.h>
//Prim's Algorithm
/*
Spanning Tree -> 
A tree in which it has 'n' nodes and 'n-1' edges and all nodes are reachable from each other.
*/
/*Minimum Spanning Tree:
A minimum spanning tree is a spanning tree which has the least sum of all its edge weights out of all 
the possible spanning tree. (A graph can have multiple minimum spanning tree)
*/
using namespace std;

/*---------------------------------------------------------------------------------------------------*/

class Solution
{
    /*
    The intuition is to take the shortest edge from the current visited vertices. (Greedy)
    Just make sure to mark a node as visited only when you reach that node. (Don't mark it as 
    visited when you found it in adjcency of other nodes)
    */
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Adjcency list is given, no need to create it
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //One visited array
        vector<int> vis(V, 0);
        
        //Since only sum is needed, we will only keep pair of : {minDist, node}
        //If the MST edges would have been asked, we will keep a pair of : {minDist, {node, parent}}
        
        //Push any first vertex to the priority queue
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()){
            //get the minimum possible edge of the current visited nodes (from the priority queue)
            auto it = pq.top();
            int node = it.second;
            int dist = it.first;
            pq.pop();
            
            
            if(!vis[node]){
                //Add the current dist considered into the sum
                sum += dist;
                for(auto it: adj[node]){
                    int adjNode = it[0];
                    int adjDist = it[1];
                    
                    if(!vis[adjNode]){
                        //Push all the edges into the priority queue provided the edge goes to unvisited node
                        pq.push({adjDist, adjNode});
                    }
                }
                
                //Mark after we pushed all the adjacent edges that satisfies the above condition 
                vis[node] = 1;
            }
        }
        
        return sum;
    }
};

/*--------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}