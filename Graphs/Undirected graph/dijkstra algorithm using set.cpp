#include<iostream>
#include<bits/stdc++.h>
//Implementing Dijktra Algorithm using Set Data Structure GFG

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

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------------------------*/

class Solution
{
	public:
	/*
	Using set data structure:
	Set can store unique values in ascending order.
	
	Similar approach to using priority queue, but in set:
	We check if the distance has already been relaxed (if it is updated to other than INT_MAX)
	-> that means the previous updated path (dist[Node]) -> {dist[Node], Node} already exits in set. 
	And since we found better path(shortest) then the current dist[Node] -> there is no point in 
	iterating for previous path (as moving to other nodes from that path will always result in longer path). 
	Hence, we remove it from the set.
	
	This improves the time complexity but to a very small degree.
	Although, it saves up on some iterations, but erase function in set takes logN times.
	The time complexity of PQ and Set approach is approx. same.
	*/
	
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //Pair of {minDist, node}
        set<pair<int,int>> s;
        
        vector<int> minDist(V, INT_MAX);
        
        //Push source node into set and minDist[source] = 0;
        minDist[S] = 0;
        s.insert({minDist[S], S});
        
        while(!s.empty()){
            auto it = *(s.begin());
            int dis = it.first;
            int node = it.second;
            s.erase(it);
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < minDist[adjNode]){
                    
                    //Check if it has been already relaxed
                    //(if updated from INT_MAX to smaller value)
                    if(minDist[adjNode] != INT_MAX){
                        //remove current {minDist[adjNode], adjNode} from set
                        //no point in iterating a node using longer path(as shorter path is found)
                        s.erase({minDist[adjNode], adjNode});
                    }
                    
                    //now update to the current shortest path
                    minDist[adjNode] = dis + edgeWeight;
                    s.insert({minDist[adjNode], adjNode});
                }
            }
        }
        
        return minDist;
    }
};

/*-----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}