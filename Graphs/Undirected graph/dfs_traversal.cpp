#include<iostream>
#include<bits/stdc++.h>
/*
DFS Traversal in a GRAPH : RECURSION

Assuming adjacency list is given in form of vector<int> adj[]

Assuming it is 0-indexed graph with n nodes
*/
using namespace std;

void dfsHelper(vector<int>& dfs1, vector<int> adj[], int node, int vis[]){
    //First mark the node as visited
    vis[node] = 1;
    dfs1.push_back(node);

    //Now, traverse through all its neigbours
    for(auto it: adj[node]){
        if(!vis[it]){
            //Now, in recursive function we send the current neighbour node as argument (it)
            dfsHelper(dfs1, adj, it, vis);
        }
    }
    return;
}

vector<int> dfs(vector<int>& dfs1, vector<int> adj[], int start, int n){
    //n is no. of nodes

    //Keep a visited array
    int vis[n] = {0};

    dfsHelper(dfs1, adj, start, vis);

    return dfs1;
}


int main(){
    //Assuming n no. of nodes
    int n = 9;

    //Assuming starting node is 0
    int start = 0;

    //FOR DFS : CALL HERE
    
    return 0;
}