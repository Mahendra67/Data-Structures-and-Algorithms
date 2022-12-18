#include<iostream>
#include<bits/stdc++.h>
//Topological sort using BFS Approach : Kahn's Algorithm
using namespace std;

//Using BFS Approach : Kahn's Algorithm
/*
If a node has indegree of 0 or it later on becomes indegree of zero, it means it can be an isolated 
node or a starting node. This means it would be on the leftmost side.
for e.g if there exists '4' node, and no edge is going inside it,
            no_node -> 4
means, it would be on the leftmost side of linear ordering.

Push the indegree[node] == 0 into queue.
After pushing it, assume it doesn't exist in graph and remove all its outgoing edges to its neighbours.
If their indegree becomes zero, that means only that edge was going inside that neighbour node, hence 
it will be on left of the current linear ordering (means can be printed).

If their indegree doesn't becomes zero, then that means there exists a node(amm) which has a edge going inside 
that current neighbour node and, that node(amm) must be printed before this neighbour node.

*/


vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    //To find indegree, just count the no. of occurence of nodes in adjaceny list
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    vector<int> topo;
	    
	    //Push all the node having indegree 0 into queue
	    //Indegree = 0  means starting node (hence leftmost position in topo sort)
	    queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        topo.push_back(node);
	        q.pop();
	        
	        //Traverse through neighbours   
	        for(auto it: adj[node]){
	            //Assume current node is removed from graph, hence remove its edges
	            //Decrease the outgoing edges to its neighbour nodes
	            indegree[it]--;
	            //If indegree becomes zero, push to queue (no more incoming edges to neighbour node
	            //, hence it can be printed now)
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
        return topo;
	}

int main(){
    
    return 0;
}