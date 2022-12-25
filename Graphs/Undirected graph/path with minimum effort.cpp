#include<iostream>
#include<bits/stdc++.h>
//Path with minimum effort LeetCode 1631
/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, 
(0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can 
move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

/*Effort is the maximum of all differences in a path*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------*/

//Approach : Using Dijktra Algorithm
class Solution {
public:
    //Using Dijktra Algorithm
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> minEffort(row, vector<int> (col, INT_MAX));
        
        //Using priority queue
        //In pair: {diff, {row, col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> pq;
        
        //Push the src mountain in the pq
        //Considering we are already at top of src mountain
        minEffort[0][0] = 0;
        pq.push({minEffort[0][0], {0,0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            
            //If you reach destination node
            /*
            We returned from here to save some iterations.
            If the destination node reaches here, that means at that time, in the min 
            priority queue, the 'diff' must be the smallest(minimum) effort to reach (2,2)
            hence it is at the top of the min priority queue.
            */
            if(r == row-1 && c == col-1){
                return diff;
            }
            
            //Traverse for its neighbours
            int possible_row[] = {-1,0,1,0};
            int possible_col[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int fr = r + possible_row[i];
                int fc = c + possible_col[i];
                
                //Check if it is a valid indexed mountain
                if(fr>=0 && fr<row && fc>=0 && fc<col){
                    //Since we need to keep track of the max effort in a path
                    //Hence, we check if travelling to adj mountains gives a bigger value.
                    int newEffort = max(abs(heights[fr][fc] - heights[r][c]), diff);
                    
                    if(newEffort < minEffort[fr][fc]){
                        minEffort[fr][fc] = newEffort;
                        
                        pq.push({minEffort[fr][fc], {fr,fc}});
                    }
                }
            }
        }
        //If unreachable
        return 0;
    }
};

/*-------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}