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