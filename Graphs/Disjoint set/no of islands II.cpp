#include<iostream>
#include<bits/stdc++.h>
//Number of islands II LeetCode 305
/*
You are given a n,m which means the row and column of the 2D matrix and an array of  
size k denoting the number of operations. Matrix elements is 0 if there is water or 1 
if there is land. Originally, the 2D matrix is all 0 which means there is no land in 
the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] 
means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how 
many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.
*/
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------*/

/*Appraoch:
Concept of connecting islands is being used and it is a dynamic graph -> Hence we use Disjoint Set

Consider each cell as a single node. To calculate node number of every single node
For matrix[row][col] -> node number will be = (total col length * row) + col

While adding islands, assume it as an indiviual island and increase the counter by 1. Now, check its adjacent 
node for whether those nodes are islands or not, if yes connect the ultimate parent of both the nodes and 
decrease the counter by 1.(Connect only if their ultimate parents are different) Do this for all adjacent nodes.
*/
class Solution {
  public:
 /*----------------------------------------------------------------------------------------------------*/ 
    class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);
            
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        
        //Find ult parent with path compression
        int findUltParent(int node){
            if(parent[node] == node){
                return node;
            }
            
            return parent[node] = findUltParent(parent[node]);
        }
        
        //Union by Size
        void unionBySize(int u, int v){
            int ult_u = findUltParent(u);
            int ult_v = findUltParent(v);
            
            if(ult_u == ult_v){
                return;
            }
            
            if(size[ult_u] > size[ult_v]){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }else{
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            
            return;
        }
    };
    
    /*----------------------------------------------------------------------------------------------------*/ 
    
    bool validCell(int adjR, int adjC, int n, int m){
        if(adjR>=0 && adjR<n && adjC>=0 && adjC<m){
            return true;
        }
        return false;
    }
    
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        //Total nodes = n*m
        //n -> total no. of rows
        //m -> total no. of columns
        DisjointSet ds(n*m);
        
        //Grid for 2D Matrix
        vector<vector<int>> grid(n, vector<int> (m,0));
        
        //Counter for no. of island
        int count = 0;
        vector<int> ans;
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            
            //If the cell has been already converted to island -> hence, no. of islands will be same
            if(grid[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            
            //If the cell is still water -> convert to land and increase counter
            grid[row][col] = 1;
            count++;
            
            //Check if its adjacent nodes are islands
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int adjR = row + dr[i];
                int adjC = col + dc[i];
                
                //Check if the adjRow and adjCol number are valid (exist in grid)
                if(validCell(adjR, adjC, n, m)){
                    //Check if adj Node is an island or not
                    if(grid[adjR][adjC] == 1){
                        //Find node number of current node and adjacent node
                        /*We have to find node no. because node numbering is done from 0 to m*n and are not
                        in [row][col] format*/
                        //m is the total no. of columns
                        int currNode = (row * m) + col;
                        int adjNode = (adjR* m) + adjC;
                        
                        //Connect the islands only if they are not in same component(diff ultimate parents)
                        //After connecting decrease the counter by 1
                        if(ds.findUltParent(adjNode) != ds.findUltParent(currNode)){
                            ds.unionBySize(adjNode, currNode);
                            
                            count--;
                        }
                    }
                }
            }
            
            //Push the count(current no. of islands) in ans
            ans.push_back(count);
        }
        
        return ans;
    }
};

/*---------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}