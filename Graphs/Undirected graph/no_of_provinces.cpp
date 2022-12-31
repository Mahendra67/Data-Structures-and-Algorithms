#include<iostream>
#include<bits/stdc++.h>
//Count no. of provinces Leetcode 547
/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------*/

//DFS Approach
class Solution {
public:
    void dfsHelper(vector<vector<int>> isConnected, vector<int>& dfs, int node, vector<int>& vis, int n){
        //Mark the node as visited
        vis[node] = 1;
        
        //Traverse in adjacency matrix to find out its neigbours
        for(int i=0; i<n; i++){
            //In the matrix, for every node, connected nodes can be found out using current node's row
            if(isConnected[node][i]==1 && vis[i]==0){
                dfsHelper(isConnected, dfs, i, vis, n);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //DFS approach
        int n = isConnected.size();
        
        //Vector to store the dfs
        vector<int> dfs;
        
        //Keep an visited array, with every value initialized to zero
        vector<int> vis(n,0);
        
        //Take a variable count to count no. of provinces
        int count = 0;
        
        for(int node = 0; node<n; node++){
            if(!vis[node]){
                count++;
                //call the dfsHelper
                int start_node = node;
                dfsHelper(isConnected, dfs, start_node, vis, n);
            }
        }
        return count;
    }
};

/*---------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
//DSU APPROACH : Disjoint Set
/*Approach :Use disjoint set data structure to attach the nodes that can be connected to other nodes in a group.

Now, just count the no. of groups formed. (No. of ultimate parents)
Different ultimate parent means different groups.
*/

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
      
    //find ultimate parent : With path compression
    int findUltParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        //If not the parent of itself(not ult parent)
        return parent[node] = findUltParent(parent[node]);
    }
    
    //Union by Size
    void UnionBySize(int u, int v){
        //Find ult parent of both vertices
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        //If they have same ult parent, that means they are already in same component
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        DisjointSet ds(n);
                
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    int node_u = i;
                    int node_v = j;
                    
                    ds.UnionBySize(node_u, node_v);
                }
            }
        }
        
        int count = 0;
        //Now, the groups are formed : Count no. of ultimate parents
        for(int i=0; i<n; i++){
            if(ds.findUltParent(i) == i){
                count++;
            }
        }
        /*
        If the parent array was declared in public access modifier, then you could have done:
        
        for(int i=0; i<n+1; i++){
            if(parent[i] == i){
                count++;
            }
        }
        */
        
        return count;
    }
};

/*---------------------------------------------------------------------------------------------------------------------*/

int main(){
    

    //DFS Approach 
    /*
    Run a loop for every node, take any node as starting point and run dfs/bfs and mark every visited node as visited in
    the visited array.
    The above algo will mark all the nodes that are connected to current node as visited. Repeat the steps for every node if it hasn't 
    been visited yet. (Do this with the help of visited array)
    Keep a counter of how many times the dfs function has been called, that will be the no. of provinces/unconnected sub-graphs.
    */
    return 0;
}