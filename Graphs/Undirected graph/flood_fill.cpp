#include<iostream>
#include<bits/stdc++.h>
//Flood Fill 733 LEETCODE
/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/
using namespace std;


//DFS Recursive Approach : Same as no. of islands approach
class Solution {
public:
    void helperDFS(vector<vector<int>>& image, int r, int c, int color, int c_node){
        int row = image.size();
        int col = image[0].size();
        
        //Update the current node
        image[r][c] = color;
        
        int possible_row[] = {-1,0,1,0};
        int possible_col[] = {0,1,0,-1};
        
        //For all neighbours
        for(int i = 0; i < 4; i++){
            //Do not r and c by r+=possible_row[i] because we need r/c original value in further iterations
            int fr = r + possible_row[i];
            int fc = c + possible_col[i];
            
            //Check if row and column index is possible or not
            if(fr >= 0 && fr < row && fc >= 0 && fc < col 
               && image[fr][fc] == c_node && image[fr][fc] != color){
                
                //Recursive call for next neighbour
                helperDFS(image, fr, fc, color, c_node);
            }
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //sr is starting row, sc is starting column
        //We do not want to directly change the given data, so copy it into a vector
        vector<vector<int>> ans = image;
        
        //Save the current colour of starting node
        int c_node = image[sr][sc];
        
        helperDFS(ans, sr, sc, color, c_node);
        
        return ans;
    }
};

int main(){
    
    return 0;
}