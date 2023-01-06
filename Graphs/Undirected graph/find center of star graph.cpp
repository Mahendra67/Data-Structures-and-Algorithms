#include<iostream>
#include<bits/stdc++.h>
//Find center of star graph Leetcode 1791
/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where 
there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between
the nodes ui and vi. Return the center of the given star graph.
*/
using namespace std;

/*-------------------------------------------------------------------------------------------------------------*/
//O(n)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //Since it is given that it is valid star graph -> means minimum of n-1 edges exist
        //where n is total no. of nodes
        int n = edges.size();
        
        //Total no. of nodes
        n = n+1;
        
        //Assume indegree of nodes is 0 at start
        vector<int> inDegree(n+1,0);
        
        for(auto it: edges){
            //u - > v
            //v - > u
            //Increase both nodes indegree by 1 (undirected graph)
            inDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        
        //Now find the node which has inDegree of n-1
        int starNode = -1;
        for(int i=1; i<=n; i++){
            if(inDegree[i] == n-1){
                starNode = i;
                break;
            }
        }
        
        return starNode;
    }
};

/*------------------------------------------------------------------------------------------------------------*/
//O(1)

/*
Observation:
Since it is given that it is a valid star node, that means each edge must be connected to center node.

Approach:
Take the first 2 edges, and return the common node -> that will be center node
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //Check if first node of first edge is common in first 2 edges
        int currNode = edges[0][0];
        
        //Check for currNode in 2nd edge (given vector)
        if(currNode == edges[1][0] || currNode == edges[1][1]){
            //if it is common, then it will be center node
            return currNode;
        }
        
        //If first node was not center node, then 2nd node must be the center node
        return edges[0][1];
    }
};

/*------------------------------------------------------------------------------------------------------------*/
int main(){
    
    return 0;
}