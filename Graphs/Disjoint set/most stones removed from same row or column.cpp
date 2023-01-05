#include<iostream>
#include<bits/stdc++.h>
//Most stones removed from same row or column
/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest 
possible number of stones that can be removed.
*/
using namespace std;

/*-------------------------------------------------------------------------------------------------------------*/

/*
If a stone is in a grid[row][col] -> all stones in that are in row and col can be removed.
And if 2 stones are not in each other's row or col, then they can't be removed.
Concept of connected components is being used -> Disjoint set

Approach:
Using Disjoint Set Data Structure:
Instead of assuming each grid cell as a node, assume/map entire row/column as a single node.
(You can also assume each grid cell as a node, but for merging 2 stones/nodes together, you have to check the entire row and entire column for other stones. ->Takes more time-> each time
O(m+n)).

Now, for every stone, union/merge row and col node's ultimate parent. This will connect all the stones that shares either the same row or same column as another stone and forms gropus for each connected component.

NOTE: For each connected component, if it has 'n' stones, a maximum of 'n-1' stones can be removed. 
e.g.
    1   0   1   0
    1   0   0   0  
    0   0   0   0
In above e.g. grid[0][0], grid[0,2], grid[1,0] forms a group. At max, only 2 of them can be removed.

Let's assume in a grid, there are 'n' stones and '4' connected components/groups.
Hence, max no. of stones that can be removed = 
        (no. of stones that can be removed from 1st component)+
        (no. of stones that can be removed from 2nd component)+
        (no. of stones that can be removed from 3rd component)+
        (no. of stones that can be removed from 4th component)
        = (n1 - 1) + (n2 - 1) + (n3 - 1) + (n4 - 1)
        = (n1 + n2 + n3 + n4) - (1+1+1+1)
        = (n) - (m)
        = (total stones) - (no. of components)
        
//n1 -> total stones in component 1

NOTE : For no. of components, just count the no. of ultimate parent.
BUT, for row/column which doesn't contain any stones, it will be the ultimate parent of itself (as it has not been connected to any other col/row). -> don't count such ultimate parents.

You can avoid this problem by 2 ways:
1. Only count those ultimate parents whose size is more than 1. (means not connected to any other row/col node).
    e.g.    
            1   0   1   0
            0   0   0   0    
            0   0   0   0          
            1   0   0   0
    The 1st indexed column has no stones in it -> it is connected to itself, (ultP of itself).
    Hence -> that column node size is 1.
    Had there been a stone present (given e.g.) it would have been connected to node of 2th row, and the size of ultimate parent would have been increased to 2.
            1   0   1   0
            0   0   0   0    
            0   1   0   0          
            1   0   0   0
            
2. Iterate over the given stones info (row and col data) -> store the ultimate parents of both row and col node in a set. This will only consider the row and col where stones are present. 
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
    int removeStones(vector<vector<int>>& stones) {
        //Total no. of stones
        int n = stones.size();
        
        //Find the maximum no. of row and col given
        int maxRowIndex;
        int maxColIndex;
        for(auto it: stones){
            maxRowIndex = max(maxRowIndex, it[0]);
            maxColIndex = max(maxColIndex, it[1]);
        }
        
        //For total no. of rows and col
        int maxRow = maxRowIndex + 1;
        int maxCol = maxColIndex + 1;
        
        //Now, Assume/map nodes from 0 to 'maxRowIndex' for entire rows.
        //And assume/map nodes from 'maxRowIndex + 1' to 'total no. of nodes' for entire columns.
        /*
        1   0   0       0th row -> 0th node             0th col -> 3rd node
        0   1   0       1st row -> 1st node             1st col -> 4th node
        0   0   0       2nd row -> 2nd node             2nd col -> 5th node
        */
        //Hence, no. of nodes needed = no.of rows + no. of columns
        DisjointSet ds(maxRow + maxCol);
        
        //Now connect the rows and column nodes for each stone position.
        for(auto it: stones){
            //Row node number = row index
            int rowNodeNumber = it[0];
            //Col node number = column index + total number of rows
            int colNodeNumber = it[1] + maxRow;
            
            ds.UnionBySize(rowNodeNumber, colNodeNumber);
        }
        
        //Now, since groups have been formed, count no. of ultimate parents/groups
        //Using 2nd approach to count : unordered set approach
        unordered_set<int> st;
        for(auto it: stones){
            int rowNodeNumber = it[0];
            int colNodeNumber = it[1] + maxRow;
            
            //You can also do this in above loop (after doing union)
            if(ds.findUltParent(rowNodeNumber) == rowNodeNumber){
                st.insert(rowNodeNumber);
            }
            if(ds.findUltParent(colNodeNumber) == colNodeNumber){
                st.insert(colNodeNumber);
            }
        }
        
        //Count the number of unique ultimate parents in set
        int count = st.size();
        
        //ans = no. of stones - no. of connected components
        return n - count;
    }
};

/*-------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}