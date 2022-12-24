#include<iostream>
#include<bits/stdc++.h>
//Implementing Dijktra Algorithm using Priority queue GFG

//NOTE : Dijktra Algorithm doesn't work for negative weights and negative weight cycles.
/*Applying Dijktras Algoritm in negative weight will cause infinite loop, since everytime you traverse through
the negative path, it will always decrease the path weight. And in PQ, the -ve path will always be considered, causing
infinite loop.
e.g.            -2
        0    <------->      1
0 can move to 1 with dist = -2. So, {-2,1} gets pushed into PQ. Now, for 1 --> 0 is adj node and the path takes -2 to reach. 
Total path to reach 0 = -2 + (-2) = -4. Since, smaller than prev path, {-4,0} gets pushed into PQ. This will keep on reapeating.
*/

/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] 
is a list of lists containing two integers where the first integer of each list j denotes there is edge 
between i and j , second integers corresponds to the weight of that  edge . You are given the source 
vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have 
to return a list of integers denoting shortest distance between each node and Source vertex S.
*/

//Why we use PQ or set instead of queue data structure?
/*
We could have used queue instead of priority queue : But if we use queue, we will have to deal with unnecessary paths.
Since in queue, data can only be accessed from front and back only. So, if by chance in adjacency list, the longer distance is given
before the shorter one, we have to process its adjacent nodes with the longer distance first (which would give overall longer distance)
and then the shorter one will be processed.
Hence, to avoid un-necessary iterations, we use min priority queue, which will one consider the minimum path that can reach a node -> and 
further process adjNode by only considering the shortest distance to current node. 
*/

using namespace std;

/*----------------------------------------------------------------------------------------------------------------*/
//TC : E log V 
//V -> no. of vertices and E is the no. of edges

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