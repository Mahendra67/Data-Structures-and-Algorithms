#include<iostream>
#include<bits/stdc++.h>
//Making a large island
/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
*/
using namespace std;

/*-------------------------------------------------------------------------------------------------------------------------------*/

/*
Concept of connected cells are used -> graph problem
We have to change cells atmost 1 time -> Dynamic graph -> hence, DisjointSet DS will be used

Approach:
Make a Disjoint Set and group all the connected components.

Now, at every cell which has 0 -> change it to 1 and check its adjacent nodes if they are a part of any component. If yes, then add that component size to the sum. Do this for all 4 directions.
NOTE : Do not change the current grid cell to 1 as it might affect the following iterations(Just assume the grid is now 1) (You can change it to 1 but make sure to change it back to zero after the current node iteration is complete)
Add 1 into the sum (for the current grid cell).


EDGE CASE : It is possible that the current grid (containing zero) is surrounded by same connected component via multiple sides.
e.g.         1    0    0
             1    0    1        "The middle zero is surrounded by same component via 3 sides"
             1    1    1
             
Hence to avoid summation of same component size, store the ultimate parent of connected components that are attached to current grid cell in a set.

Do the above for every cell containing zero, and return the max size of island formed.

*/
class DisjointSet{
public:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    //Find ultimate parent
    int findUltParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    //Union By Size
    void UnionBySize(int u, int v){
        //Find ultimate parent of u and v
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        if(ult_u == ult_v){
            //In same component
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

class Solution {
public:
    //Check if it is valid cell
    bool validCell(int adjR, int adjC, int row, int col){
        return adjR>=0 && adjR<row && adjC>=0 && adjC<col;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        //Form all the connected components
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 1){
                    //Check if neighbours are also island, if yes join them
                    for(int i=0; i<4; i++){
                        int adjR = r + dr[i];
                        int adjC = c + dc[i];
                        
                        if(validCell(adjR, adjC, n, n)){
                            if(grid[adjR][adjC] == 1){
                                int currNode = (r * n) + c;
                                int adjNode = (adjR * n) + adjC;
                                ds.UnionBySize(currNode, adjNode);
                            }
                        }
                    }
                }
            }
        }
        
        
        //Now the groups have been formed
        int maxSize = INT_MIN;
        
        //For every grid containing zero, check the size of island it forms
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 0){ 
                    int size = 0;
                    
                    //Set for storing ultimate parent of adjNode having 1
                    unordered_set<int> s;
                    
                    //Check neighbours if they are part of a component
                    for(int i=0; i<4; i++){
                        int adjR = r + dr[i];
                        int adjC = c + dc[i];
                        
                        if(validCell(adjR, adjC, n, n)){
                            //Check if adjNode are islands
                            if(grid[adjR][adjC] == 1){
                                //Instead of adding here, insert the ultimate parent of adjNode into set
                                int adjNode = (adjR * n) + adjC;
                                int ultAdjNode = ds.findUltParent(adjNode);
                                
                                s.insert(ultAdjNode);
                            }
                        }
                    }
                    
                    //Now, add the size of the components surrounding the curr node
                    //i.e. sum of size of ultimate parent in set
                    for(auto it: s){
                        size += ds.size[it];
                    }
                    
                    //Add 1 into the size for current island/node
                    size++;
                    
                    //Update maxSize if you find a bigger size island
                    maxSize = max(maxSize, size);
                }
            }
        }
        
        //Edge case : If there is no water(0) -> every grid cell is 1
        if(maxSize == INT_MIN){
            //If max size is still INT_MIN, only possible if every grid cell is 1
            //Hence max island size = n*n
            return n*n;
        }
        //If it reaches here, means there was atleast 1 grid cell containing zero
        
        return maxSize;
    }
};

/*-------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}