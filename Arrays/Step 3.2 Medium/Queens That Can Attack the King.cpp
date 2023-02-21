#include<iostream>
#include<bits/stdc++.h>
//Queens that can attack the king Leetcode 1222

/*
On a 0-indexed 8 x 8 chessboard, there can be multiple black queens ad one white king.

You are given a 2D integer array queens where queens[i] = [xQueeni, yQueeni] represents the position of the ith 
black queen on the chessboard. You are also given an integer array king of length 2 where king = [xKing, yKing] 
represents the position of the white king.

Return the coordinates of the black queens that can directly attack the king. You may return the answer in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
Approach:
Construct the board from the given queens position vector.
Now, from king's position go in every 8 direction, and if you find a queen, add that queen into the vector.
*/
class Solution {
public:
    //kr is king's row index
    //kc is king's col index
    void traceQueen(vector<vector<bool>>& board, int kr, int kc, vector<vector<int>>& ans){
        int row = kr;
        int col = kc;
        
        //Travel in all 8 directions
        //Vertically up
        //Vertically down
        //Horizontally left
        //Horizontally right
        //Diagonally up left
        //Diagonally up right
        //Diagonally down left
        //Diagonally down right
        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
        
        for(int i=0; i<8; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            //Check for validity and check if you find any queen in that path
            while(nr >= 0 && nc >= 0 && nr < 8 && nc < 8){
                if(board[nr][nc] == true){
                    ans.push_back({nr, nc});
                    break;
                }
                nr = nr + dr[i];
                nc = nc + dc[i];
            }
        }
        
        return;
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //Construct the board
        vector<vector<bool>> board(8, vector<bool> (8, false));
        
        for(auto it: queens){
            board[it[0]][it[1]] = true;
        }
        
        vector<vector<int>> ans;
        
        //Now, look in all 8 directions from king's perspective
        traceQueen(board, king[0], king[1], ans);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/