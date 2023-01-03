#include<iostream>
#include<bits/stdc++.h>
//Krushkal Algoritm
using namespace std;

/*----------------------------------------------------------------------------------------------------------*/

class Solution
{       
    /*---------------------------------------------------------------------------------------------*/
    //Class for DisjointSet
    class DisjointSet{
        vector<int> parent, size;
        
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);
            
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        
        //Find ultimate parent with path compression
        int findUltParent(int node){
            if(parent[node] == node){
                return node;
            }
            
            //If not the ultimate parent of itself, give recursive call to find parent of current node's parent
            return parent[node] = findUltParent(parent[node]);
        }
        
        //Union by size
        void UnionBySize(int u, int v){
            //Find ultimate parent of u and v
            int ult_u = findUltParent(u);
            int ult_v = findUltParent(v);
            
            //If same ultimate parent, do nothing as they are already in same component
            if(ult_u == ult_v){
                return;
            }
            
            if(size[ult_u] > size[ult_v]){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
            else{
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            
            return;
        }
    };
    
    /*---------------------------------------------------------------------------------------------------*/
    
    /*
    Krushkal Algorithm:
    1. Sort the edges by their distances
    2. Use disjoint set to connect vertexes if they are not in same component using Union by Rank or Size.
    */
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Adjacency list is given
        //Store {dist, {u,v}} pairs in vector
        
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0; i<V; i++){
            int node_u = i;
            for(auto it: adj[i]){
                int node_v = it[0];
                int weight = it[1];
                
                //Push the edge info in vector (edges)
                edges.push_back({weight, {node_u, node_v}});
                
                //Since it is undirected graph, the same edge is going to be pushed twice in the vector.
                /*
                But, during union the duplicate will be ignored 
                (as one will be attached to a component (u -> v),
                and during iteration for duplicate one (v -> u) -> it will observe that the nodes v and u are
                already in same component. -> hence ignored).
                */
            }
        }
        
        //Now the edges info vector has been created
        //Apply Krushkal Algorithm
        
        //1. Sort the edges info vector according to distance
        sort(edges.begin(), edges.end());
        
        //2. Now attach every node by union by size. Assuming every node is isolated at starting
        DisjointSet ds(V);
        
        int sum = 0;
        
        for(auto it: edges){
            //Check if the vertices that are connected by an edge is already in a component
            //If not, attach their ultimate parent to the current component by union of size
            //Since it is sorted by distance, it will attach by the current shortest path it can find
            int u = it.second.first;
            int v = it.second.second;
            int wt= it.first;
            
            if(ds.findUltParent(u) != ds.findUltParent(v)){
                ds.UnionBySize(u, v);
                
                //Add to the overall sum
                sum += wt;
            }
        }
        
        return sum;
    }
};

/*---------------------------------------------------------------------------------------------------------------*/