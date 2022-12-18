#include<iostream>
#include<bits/stdc++.h>
/*
BFS Traversal in a GRAPH : QUEUE DATA STRUCTURE

Assuming adjacency list is given as vector<int> adj[];

Visited array is kept for marking visited nodes
*/
using namespace std;

vector<int> bfs(int start, vector<int> &bfs1, vector<int> adj[], int n){
    //Visited array of 
    int vis[n] = {0};

    queue<int> q;
    //Push back the starting node
    q.push(start);
    //Mark the node as visited
    vis[start] = 1;


    //Do the following until the queue becomes empty (no more neighbours to visit)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs1.push_back(node);

        //To raverse through all neigbours of node from adjacency list 
        for(auto it: adj[node]){
            //Check if the node is already visited, if not update to 1 in visited array and push to queue
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs1;
}

int main(){
    //Assuming n nodes
    int n = 9;

    vector<int> bfs1;
    //Assuming starting node is 0
    int start = 0;
    

    return 0;
}