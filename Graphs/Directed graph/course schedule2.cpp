#include<iostream>
#include<bits/stdc++.h>
//Course Schedule 2 Leetcode 210
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
return any of them. If it is impossible to finish all courses, return an empty array.
*/
using namespace std;

//BFS (topo sort approach) : Same approach but we are returning array of topo sort
class Solution {
public:
    //Return topo sort linear ordering
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        //Create graph
        vector<vector<int>> graph(n);
        
        for(auto it: prerequisites){
            int node1 = it[0];
            int node2 = it[1];
            /*Since relation is node2 then node1, hence
            we push node1 in node2th row*/
            graph[node2].push_back(node1);
        }
        
        //Create indegree vector
        vector<int> indegree(n,0);
        vector<int> topo;
        
        //Calculate indegree for every node
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                indegree[it]++;
            }
        }
        
        //Push nodes having indegree=0 into queue
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it: graph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        //If no. of nodes in topo vector is not equal to total no. of vertices, that means there exists a cycle
        if(topo.size()!=n){
            topo.clear();
        }
        return topo;
    }
};

int main(){
    
    return 0;
}