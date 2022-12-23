#include<iostream>
#include<bits/stdc++.h>
//Implementing Dijktra Algorithm using Priority queue GFG

//NOTE : Dijktra Algorithm doesn't work for negative weights and negative weight cycles.

/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] 
is a list of lists containing two integers where the first integer of each list j denotes there is edge 
between i and j , second integers corresponds to the weight of that  edge . You are given the source 
vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have 
to return a list of integers denoting shortest distance between each node and Source vertex S.
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------------*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //Declare min pq
        //It will be storing pairs of {edgeWeight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //Min dist array
        vector<int> minDist(V, INT_MAX);
        
        //Push the source node into the pq
        minDist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                //Relaxation of edges
                if(dist + edgeWeight < minDist[adjNode]){
                    minDist[adjNode] = dist + edgeWeight;
                    
                    //If you find a smaller path, push the min_dist and that adj node into pq
                    pq.push({minDist[adjNode], adjNode});
                }
            }
        }
        
        return minDist;
    }
};

/*----------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}