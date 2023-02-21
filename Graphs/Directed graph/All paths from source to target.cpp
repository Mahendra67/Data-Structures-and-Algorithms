#include<iostream>
#include<bits/stdc++.h>
//All paths from source to target Leetcode 797

/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 
to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a 
directed edge from node i to node graph[i][j]).
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    : O(n) + O(n) -> Recursive stack(at max n recursive calls will be there in stack space)
        and another O(n) for temp vector.
*/

//Basic DFS 
class Solution {
public:
    vector<vector<int>> ans;
    
    void validPaths(int node, vector<vector<int>>& adj, vector<int>& temp){
        //Base cases
        int lastNodeNo = adj.size() - 1;
        if(node == lastNodeNo){
            temp.push_back(lastNodeNo);
            ans.push_back(temp);
            temp.pop_back();
            
            return;
        }
        
        //from the current node -> travel to neigbhouring nodes
        //node -> current node number
        for(auto adjNode: adj[node]){
            temp.push_back(node);
            validPaths(adjNode, adj, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        
        validPaths(0, graph, temp);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/