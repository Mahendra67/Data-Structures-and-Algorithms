#include<iostream>
#include<bits/stdc++.h>
//Reductant Connection LeetCode 684
/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional 
edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that 
already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] 
indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are 
multiple answers, return the answer that occurs last in the input.
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------*/

class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i=1; i<n+1; i++){
            parent[i] = i;
        }
    }
    
    //Find ultimate parent
    int findUltParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    //Union by Size
    void UnionBySize(int u, int v){
        int ultV = findUltParent(v);
        int ultU = findUltParent(u);
        
        if(ultV == ultU){
            return;
        }
        else if(size[ultV] > size[ultU]){
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
        }else{
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
        }
        return;
    }
};

/*Approach : Tree will never have a cycle. Use disjoint set to connect each node to an ultimate parent. If you find another edge of nodes that are already connected in same component, that will be the extra edge.

Since, we require the answer that occurs last in input -> keep a vector and keep updating teh if you find another extra edge*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //Number of nodes is the size of edges vector (as one node is extra)
        int n = edges.size();
        DisjointSet ds(n);
        
        vector<int> ans;
        for(auto it: edges){
            int node1 = it[0];
            int node2 = it[1];
            
            if(ds.findUltParent(node1) != ds.findUltParent(node2)){
                //Attach them
                ds.UnionBySize(node1, node2);
            }else{
                //this is the extra edge
                //clear the previous ans
                ans.clear();
                ans.push_back(node1);
                ans.push_back(node2);
            }
        }
        
        return ans;
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}