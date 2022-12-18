#include<iostream>
#include<bits/stdc++.h>
//Cycle detection in directed graph using BFS approach: Topological sort

using namespace std;

/*
Approach 2: If you apply topo sort to a directed cyclic graph, you won't be able to produce 'n' vertices.
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    //BFS Approach : Kahn's Algorithm
    /*Since it can only end it queue becomes empty. If queue becomes empty, then all nodes whose indegree can
    be changed to 0 according to the nodes in queue is completed.
    And if there exists a node whose indegree doesn't becomes zero, then there exists a cycle*/
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        
        //Find indegree of nodes
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        //push all nodes with indegree=0 in queue
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        //Check if there is any node whose indegree is still not 0
        for(int i=0; i<V; i++){
            if(indegree[i]!=0){
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}