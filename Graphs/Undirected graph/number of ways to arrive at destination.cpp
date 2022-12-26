#include<iostream>
#include<bits/stdc++.h>
//No. of ways to arrive at destination LeetCode 1976
/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional 
roads between some intersections. The inputs are generated such that you can reach any intersection 
from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means 
that there is a road between intersections ui and vi that takes timei minutes to travel. You want 
to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest 
amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since
the answer may be large, return it modulo 109 + 7.
*/
using namespace std;

/*-------------------------------------------------------------------------------------------------------------------------*/
//Modified Dijktra Algorithm
/*
We will not use normal Dijktra Algorithm, because there may be 2 or more differnt paths with shortest distance but they merge in the middle somewhere before meeting the end node. If we use normal Dijktra Algorithm and count the no. of min. path that touch end node, it will count those paths as 1.

Hence, we take a path[] which stores no. of paths by which we can reach a node in minimum distance.
Initialize path[src] = 1, as there is only one way to start. Rest other mark as 0.

Why we use the following line to update path?
i.e. path[adjNode] = path[adjNode] + path[currNode];

e.g. Assume the given paths are of equal distance, and 
        1     2     3
        \     |     /
         \    |    /
          \   |   /
              4
          /  /|\  \
         /  / | \  \
      a / b/ c|  \d \e
        \  \  |  /  /
         \  \ | /  /
          \  \|/  /
              5
No. of paths to reach 5 = (3 paths to reach 4, then path a)
                          +(3 paths to reach 4, then path b)
                          +(3 paths to reach 4, then path c)
                          +(3 paths to reach 4, then path d)
                          +(3 paths to reach 4, then path e)
Hence, for each path to reach adjNode (with same shortest distance), we have to update the no. of paths of adjNode by current no. of paths to reach adjNode + no. of paths to reach its parent node.         
*/

/*
Also, since the input time is 10e9, we have to use long long instead of int (to avoid overflow)
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        
        //create adj list
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        //2 arrays
        vector<long long> minTime(n,LLONG_MAX);
        //Initialize no. of paths to zero
        vector<int> paths(n,0);
        
        //Dijktra Algorithm
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, 
                        greater<pair<long long,int>>> pq;
        
        //Push src to PQ : Pair :{time, node}
        pq.push({0, 0});
        //Mark no. of paths to reach src node as 1
        paths[0] = 1;
        minTime[0] = 0;
        
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                long long adjTime = it.second;
                
                if(time + adjTime < minTime[adjNode]){
                    //First time reaching a node with smaller distance
                    minTime[adjNode] = time + adjTime;
                    //Push into PQ
                    pq.push({minTime[adjNode], adjNode});
                    
                    //Since it it first time reaching a node with smaller distance
                    /*The no. of ways to visit this node (with that smaller distance)
                    is equal to no. of ways to reach its parent node*/
                    paths[adjNode] = paths[node];
                    
                }else if(time + adjTime == minTime[adjNode]){
                    //Another path has also the same shortest distance
                    paths[adjNode] = (paths[adjNode] + paths[node]) % MOD;
                    /*Do not push into the queue as {minTime[adjNode], adjNode} 
                    is already present in queue */
                }
            }
        }
        return (paths[n-1]) % MOD;
    }
};

/*-------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}