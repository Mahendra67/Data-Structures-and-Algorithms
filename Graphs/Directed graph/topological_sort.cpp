#include<iostream>
#include<bits/stdc++.h>
//Topological sort using DFS
//Only exists in DAG - Directed acylic graph
//Not possible for Undirected graph and cyclic graphs

/*
INTUITION : 
taking in consideration the graph 1->2->3->4 : 
we start with the dfs(1) we keep calling it for the adjacent nodes and at the very end 
we reach dfs(4) WHICH DOES NOT HAS ANY ADJ NODE, thus we put it in the stack stating that there is no node 
it needs to point after completion we push 3 in the stack stating that all the nodes pointed by 3 must already be the stack, 
same way we go up and at the end we push 1 in the stack stating that all the nodes pointed by 1 are already in the stack in a linear order.
Linear order if a node v points to u then v comes first then u.
*/

/*
Linear ordering of vertices such that if there exists an edge between u and v, then u must appear before v in ordering.
eg.
    5 -> 0
    5 -> 2
    2 -> 3
    3 -> 1
    4 -> 1
    4 -> 0

Suppose the above directed graph, then the topological sort will be/ valid linear ordering will be:

    5 4 2 3 1 0 
*/

using namespace std;


//DFS APPROACH USING VECTOR
/*You can also use stack to store the elements, and after the dfs for whole graph is done, 
start popping from stack and add to the answer vector*/
class Solution
{
    private:
    void dfs(vector<int> adj[], vector<int>& vis, int node, vector<int>& topo){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it, topo);
            }
        }
        
        //If it reaches here, means the dfs call for the current node is completed, 
        //no more nodes to visit, start putting it from the rightmost place.
        //You can either use a stack, or a vector(but in end, you need to reverse the vector)
        
        topo.push_back(node);
        return;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    vector<int> topo;
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(adj, vis, i, topo);
	        }
	    }
	    
	    //Reverse the vector, since it started to add nodes from left, but we need the rev order
	    reverse(topo.begin(),topo.end());
	    
	    return topo;
	}
};



int main(){
    
    return 0;
}