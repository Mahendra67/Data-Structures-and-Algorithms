#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Kosaraju algorithm for Strongly Connected Components

/*
Strongly connected components are only valid for directed graph.

Strongly Connected Components are those components in which for every 2 nodes (assume nodeU and nodeV),
there exists a path between nodeU to nodeV and also a path between nodeV to nodeU.
i.e.    u   ->   v
also,   v   ->   u

1. Find no. of strongly connected components
2. Print all strongly connected components
*/

/*------------------------------------------------------------------------------------------------------------*/

/*
Kosaraju Algorithm:
1.Sort all the edges according to finishing time.
2.Reverse the graph.
    Reversing the edges will help in segregating SCC. But inside SCC, reversing the edges will not effect it as 
    in SCC for any 2 pair of node, there exists a path from nodeA to nodeB and from nodeB to nodeA.
3. Do a DFS
*/

/*------------------------------------------------------------------------------------------------------------*/

class Solution
{   
    //STEP 1 DFS
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
        //Mark as visited
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        //Once it completes current node iteration, push into stack
        st.push(node);
    }
    
    //STEP 3 DFS
    void dfs2nd(int node, vector<vector<int>> revGraph, vector<int>& vis){
        //Mark visited
        vis[node] = 1;
        
        for(auto it: revGraph[node]){
            if(!vis[it]){
                dfs2nd(it, revGraph, vis);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //STEP 1:
        vector<int> vis(V,0);
        //Stack to store nodes according to their dfs traversal finishing time
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        
        //Step 2:
        //make a graph with reversed edges
        /*Reversing the graph isolates the strongly connected components(SCC), while in the SCC
        has no limitaion to reach the nodes within the SCC as there are always 2 ways b/w any 2 nodes*/
        vector<vector<int>> revGraph(V);
        
        for(int i=0; i<V; i++){
            //mark every node as unvisited as we are going to use same array
            vis[i] = 0;
            for(auto it: adj[i]){
                //In adj list, edge exists b/w i -> it
                //We need it -> i
                revGraph[it].push_back(i);
            }
        }
        
        
        //Step 3:
        int countScc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                //Increase count
                countScc++;
                
                //Traverse all the nodes reachable from this node
                dfs2nd(node, revGraph, vis);
            }
        }
        
        return countScc;
    }
};

/*------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}