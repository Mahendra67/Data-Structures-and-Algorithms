#include<iostream>
#include<bits/stdc++.h>
//Floyd-Warshall Algorithm
/*
The problem is to find the shortest distances between every pair of vertices in a 
given edge-weighted directed graph. The graph is represented as an adjacency matrix 
of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, 
it means there is no edge from i to j.
Do it in-place.
*/

//Floyd_Warshall ALgorithm TC : O(N^3)

/*
You can use Dijktra's Algorithm on every single vertex provided that it must not contain any negative cycles.
Dijktra TC would be : O(VE*logV)
*/
using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Floyd-Warshall Algorithm : Multiple source shortest path. 

Using floyd-warshall Algorithm we can find out shortest distance between every pair of vertices in an 
edge-directed graph. It also helps to detect negative weight cycles.

The idea is to one by one pick all vertices and updates all shortest paths which include the picked 
vertex as an intermediate vertex in the shortest path. 
It means if you are considering path between i->j, then pick all vertices as an intermediate between the 
path (i -> k -> j) and check if you find a smaller path. Here, k is picked one by one from all vertices.

*/

class Solution {
  public:
  /*
  It is given in problem that if there doesn't exist an edge between 2 vertices, -1 is present in adjacency
  matrix.
  Since, we need to relax the edges, we need to change it to larger values like 1e9.
  Don't use INT_MAX as we are adding different elements -> chances of integer overflow.
  
  At the end of the algorithm, if any vertices can't be visited, mark them back to -1.
  */
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    //Change the -1 to INT_MAX
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	            //Also, dist to itself will be zero
	            if(i == j){
	                matrix[i][i] = 0;
	            }
	        }
	    }
	    
	    //MAIN FLOYD-WARSHALL ALGORITHM
	    /*----------------------------------------------------------------------------------*/
	    
	    //Pick up each vertices as an intermediate node/vertex ('via' node)
	    for(int via=0; via<n; via++){
	        //For each 'via' node, check if there exists a shorter path if we take 'via' node
	        //i -> via -> j
	        //i and j are path end vertices and 'via' is the intermediate node
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                //Store the shorter path in current matrix[i][j]
	                /*Compare with previously stored value and
	                (cost to reach 'via' node from i + cost to reach j node from 'via' node) */
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    /*----------------------------------------------------------------------------------*/
	    
	    //To check for negative weight cycle
	    /*
	    In an adjacency matrix, cost to reach 'i'th node from itself is zero.
	    i.e. matrix[i][i] = 0
	    
	    If there exists a negative weight cycle, it will update matrix[i][i] to a negative value.
	    e.g.
	                      -2        -3
                	    -------->c-------->-
                	    |                   |
                	    a<------------------b
	                            2
	                            
	   From 'a' node to 'a' using 'b' as intermediate node, 
	            cost from a->b = -5
	            cost from b->a = 2
	            total cost = -3 which is less than zero, and the above algo will update
        matrix[a][a] = -3.
        
        Hence, to detect a negative cycle, just run a loop on the adjacency matrix to check if 
        any node has self loop as a negative number.
	    */
	    
	   /*
	    
	    for(int i=0; i<n; i++){
	        if(matrix[i][i] < 0){
	            cout<<"Negative loop";
	            break;
	        }
	    }
	    
	    */
	    /*-----------------------------------------------------------------------------------*/
	    
	    
	    /*If any vertices remains unvisited( matrix[i][j] == INT_MAX ) -> change it back to -1. (problem has 
	    stated that if no edges exist, it will be -1 in adjaceny matrix) */
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	    
	    return;
	}
};

/*-----------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}