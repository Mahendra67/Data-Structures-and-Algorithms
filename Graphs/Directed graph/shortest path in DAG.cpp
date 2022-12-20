#include<iostream>
#include<bits/stdc++.h>
//Shortest path in directed acyclic graph GFG
/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D 
Integer array(or vector) edges[ ][ ] of length M, where there is a 
directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] 
for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if 
it is impossible to reach any vertex, then return -1 for that vertex.
*/
using namespace std;

/*
Approach:
1. Do a topo sort of the graph.
2. Take an minDist[] array in which every element is intialized to infinty.
3. From leftmost elemtent of the topo sort, traverse through its neighbours and relax its edges.
    For every neighbour element, if you find a path length less than what you stored in minDist[],
    update/relax that path length.
    
Intuition:
We used topo sort because, it gives us the linear ordering of reachability to a certain node.
Consider the following (topo sort) linear ordering:

1   2   3   4   5   6

To reach 3, we can only go via node 1 and node 2 only(since it is a directed graph). 
The nodes 4,5,6 can't go to node 3.

And in the used algorithm, we need the minDis of preceeding node(the nodes that can visit the 
current neighbouring node) to calulate the minimum distance to the current neighbouring node.
(hence we need to calculate the previous nodes prior)

Processing the nodes in topological order makes sure that by the time we reach a node, it have already
processed the nodes preceeding it (reduces time complexity).

*/
class Solution {
    //helper dfs 
    void dfs(vector<vector<pair<int,int>>> adj, vector<int>& vis, stack<int>& st, int node){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            int n = it.first;
            int wt = it.second;
            if(!vis[n]){
                dfs(adj, vis, st, n);
            }
        }
        
        st.push(node);
        return;
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        /*Given edges format : [[node1, node2, weight]]
        node1->node2 with 'weight'*/
        
        //Make the adjacency list
        vector<vector<pair<int,int>>> adj(N);
        
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        //Apply topo sort here (DFS)
        stack<int> st;
        vector<int> vis(N,0);
        
        
        //Start looking from source node
        //Set the source node (Here, it is zero)
        int src = 0;
        
        //call from dfs(0) -> call all the nodes that can be visited from source node 0.
        //If any node can't be visited from source node, then we can't consider them in the path
        dfs(adj, vis, st, src);
        
        //Now the stack is ready, take a minDist[] and initialize each element to infinity
        vector<int> minDis(N,INT_MAX);
        

        //Set the minDist of src node to itself zero
        minDis[src] = 0;
        
        
        // O(N + M)
        while(!st.empty()){
            //take out each element (Start from left to right in topo sort)
            int node = st.top();
            st.pop();
            
            //Traverse to all its neighbours
            /*If you find the path distance is to neighbour node is smalller than what was saved in
            minDis[node], then update it to smaller one*/
            
            //This inner loop will run for overall M edges
            for(auto it: adj[node]){
                //n is the neighbour node and wt is the weight/distance to get to that node
                int n = it.first;
                int wt = it.second;
                
                //current minimum distance to the current node + dist to travel to neigbour node
                //if the above is smaller than the minDis[neighbour node], update it to smaller one
                int currPathDist = minDis[node] + wt;
                
                if(currPathDist < minDis[n]){
                    minDis[n] = currPathDist;
                }
            }
            
        }
        
        //Edge case : What if the node is not reachable
        //Check in minDis[] if any one has minDis still set to infinity, if yes, change that to -1
        for(int i=0; i<N; i++){
            if(minDis[i] == INT_MAX){
                minDis[i] = -1;
            }
        }
        
        return minDis;
    }
};

int main(){
    
    return 0;
}