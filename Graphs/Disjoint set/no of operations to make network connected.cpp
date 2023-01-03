#include<iostream>
#include<bits/stdc++.h>
//No. of operations to make network connected LeetCode 1319
/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections 
forming a network where connections[i] = [ai, bi] represents a connection between computers 
ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between 
two directly connected computers, and place them between any pair of disconnected computers to 
make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. 
If it is not possible, return -1.
*/
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------*/

/*
For n nodes/components, the minimum no. of edges required such that all nodes/components are
connected will be n-1 edges.

Approach: Use disjoint set data structure to find out no. of connected components.
Also, find the no. of extra edges.
If no. of extra edges >= ((no. of groups of nodes/component) - 1), then return 
(no. of connected components - 1)

*/
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    //Find ultimate parent with path compression
    int findUltParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    //Union by size
    void UnionBySize(int u, int v){
        //Find ultimate parent of both node u and node v
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        if(ult_u == ult_v){
            return;
        }
        
        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        
        return;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //Count no. of components formed (Same as no. of provinces problem)
        DisjointSet ds(n);
        
        //No. of extra edges
        int extraEdges = 0;
        
        for(auto it: connections){
            int nodeU = it[0];
            int nodeV = it[1];
            
            if(ds.findUltParent(nodeU) == ds.findUltParent(nodeV)){
                //Already in same component -> Extra edge
                extraEdges++;
            }else{
                ds.UnionBySize(nodeU, nodeV);
            }
        }
        
        int compNo = 0;
        //No. of components formed = No. of ultimate parent
        for(int i=0; i<n; i++){
            if(ds.findUltParent(i) == i){
                compNo++;
            }
        }
        
        //min. no. of edges required to connect n nodes/component = n-1 edges
        int minEdges = compNo - 1;
        
        //Now, check if we have sufficient no. of extra edges or not
        if(extraEdges >= minEdges){
            return minEdges;
        }else{
            return -1;
        }
    }
};

/*---------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}