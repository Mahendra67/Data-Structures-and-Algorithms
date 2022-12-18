#include<iostream>
#include<bits/stdc++.h>
//Is graph bipartite Leetcode785
/*
A graph is bipartite if the nodes can be partitioned into two independent sets A 
and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

/*
Bipartite graph : If you can colour a graph with just 2 colours such that 
                  no adjacent graph verices have the same colour.

Note : A linear graph with no loops/cycle is always a bipartite graph. 

Also, if in a cycle, no. of vertices is even, then it is bipartite graph.
If odd, then it is not bipartite graph.
*/

using namespace std;

//BFS
class Solution {
public:
//BFS APPROACH : Adjacency list is given
//Try to colour the graph with only 2 colours such that adjacent nodes are of different colour.
//If it is not possible, return false
    
    //Works also for multiple seperate connected components
    bool helper(vector<vector<int>>& graph, vector<int> &color, int start){
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            //n_node is for neigbouring node
            for(auto n_node: graph[node]){
                /*Check if it is not yet coloured and color it opp. of adjacent
                previous node*/
                if(color[n_node] == -1){
                    color[n_node] = !color[node];
                    q.push(n_node);
                }else if(color[n_node] == color[node]){
                    //Not a bipartite graph, since 2 adjacent nodes can't have same color
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        //No. of nodes
        int n = graph.size();

        //Instead of visited array, keep a colour array 
        vector<int> color(n,-1);
        //Colors are assumed to be 0 or 1, and -1 represents non-coloured

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                //i will be starting node
                if(helper(graph, color, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};


//DFS Traversal but same approach
class Solution {
public:
    //Same approach but DFS Traversal
    bool dfs(vector<vector<int>> graph, vector<int>& color, int src, int c){
        color[src] = c;
        
        for(auto it: graph[src]){
            if(color[it] == -1){
                //Pass the opposite color of current color
                if(dfs(graph, color, it, !c)==false){
                    return false;
                }
            }else if(color[it] == c){
                return false;
            } 
            /*Since we stored c in color[src], 
            we will check if negihbour color is equal to c*/
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n,-1);
        //Assuming 0 and 1 as colors
        int start_color = 0;
        
        for(int it=0; it<n; it++){
            if(color[it] == -1){
                int start_node = it;
                if(dfs(graph, color, start_node, start_color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    
    return 0;
}