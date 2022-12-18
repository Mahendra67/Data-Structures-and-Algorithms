#include<iostream>
#include<bits/stdc++.h>
//Course Schedule I Leetcode 207

//Creation of a graph

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/
using namespace std;

class Solution {
public:
    //Cycle detection approach: Topo sort (BFS)
    /*
    If cycle is present, return false; else true;
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        
        //Create the graph from given relations
        //Don't give predefined values to graph
        vector<vector<int>> graph(numCourses);
        
        for(auto it: prerequisites){
            int node1 = it[0];
            int node2 = it[1];
            graph[node1].push_back(node2);
        }
        
        //Count the indegree of each node
        for(int i=0; i<numCourses; i++){
            for(auto it: graph[i]){
                indegree[it]++;
            }
        }
        
        //Push nodes with indegree = 0 in queue
        vector<int> topo;

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it:graph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        
        if(topo.size()==numCourses){
            return true;
        }
        return false;
    }
};

int main(){
    
    return 0;
}