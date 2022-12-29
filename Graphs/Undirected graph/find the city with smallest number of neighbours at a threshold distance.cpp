#include<iostream>
#include<bits/stdc++.h>
//Find the city with smallest numeber of neighbours at a threshold distance Leetcode 1334

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance 
is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights 
along that path.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------*/

/*
Approach : Using Floyd-Warshall Algorithm
Make adjacency matrix. Apply Floyd Warshall Algorihm.

Now, we have shortest path of all node pairs(after applying floyd-warshall),
check for every node, and count the no. of neighbours that it can visit that are at a
threshold distance. Return the node which have the smallest no. of neighbours at threshold distance. (If neighbour count becomes same, return the greater node number.)

*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Create adjacency matrix
        vector<vector<int>> adjMatrix(n, vector<int> (n, 1e8));
        
        for(auto it: edges){
            int row = it[0];
            int col = it[1];
            int wt = it[2];
            adjMatrix[row][col] = wt;
            //Since undirected graph
            adjMatrix[col][row] = wt;
        }
        
        //Set distance of a node to itself as 0
        for(int i=0; i<n; i++){
            adjMatrix[i][i] = 0;
        }
        
        //Apply Floyd-Warshall Algorithm
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    //Relax the edge if you find a smaller path
                    //(cost from i to via node) + (cost from via to j node)
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                }
            }
        }
        
        //Store the ans in a pair {src, neighbour_count}
        //neighbour count is defaulted to 1e8 since we need to relax it
        pair<int,int> ans = {0,1e8};
        
        //Now, we have the matrix with all node pairs shortest paths
        for(int i=0; i<n; i++){
            int src = i;
            int count = 0;
            for(int j=0; j<n; j++){
                if(i!=j && adjMatrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            
            //Check if you find a smaller count
            //OR if it has same count-> update to greater node number
            //if(ans.second > count || (ans.second == count && ans.first < i))
            //We didn't use ans.first < i, as it will always be true (loop if from i=0 -> n-1)
            if(ans.second >= count){
                ans = {src, count};
            }
        }
        
        return ans.first;
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

/*
Approach:
Apply Dijktra Algorithm on each vertex and count the no. of neighbours at a threshold distance.
Store the {node, neighbour_count} in a pair. Update it if you find smaller neighbour count
or same neighbour count but greater node number.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Make adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        //To store the pair of {node, neighbour_count}
        //We stored 1e8 in neighbour default count as we need to relax it later on.
        pair<int,int> ans = {0,1e8};
        
        //Apply Dijktra's Algorithm for each node
        for(int vertex=0; vertex<n; vertex++){
            //Dijktra Algorithm
            int src = vertex;
            
            //Min Dist array
            vector<int> minDist(n, 1e8);
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            
            //Mark src node minDist as 0
            minDist[src] = 0;
            //Pair : {dist, node}
            pq.push({minDist[src], src});
            
            while(!pq.empty()){
                auto it = pq.top();
                int node = it.second;
                int dist = it.first;
                pq.pop();
                
                for(auto it: adj[node]){
                    int adjNode = it.first;
                    int adjDist = it.second;
                    
                    if(dist + adjDist < minDist[adjNode]){
                        minDist[adjNode] = dist + adjDist;
                        
                        pq.push({minDist[adjNode], adjNode});
                    }
                }
            }
            
            int count = 0;
            //Now, count the no. of neighbours that are atmost at a distance of threshold
            for(int i=0; i<n; i++){
                //Don't consider the src node to itself (which will be zero)
                if(i!=src && minDist[i] <= distanceThreshold){
                    count++;
                }
            }
            
            //Check if you found a smaller count of neighbours 
            //OR
            //if you found same no. of neighbours but greater node value
            //if(ans.second >= count)
            if(ans.second > count || (ans.second == count && ans.first < src)){
                //Update ans
                ans = {src, count};
            }
            
        }
        
        return ans.first;
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}