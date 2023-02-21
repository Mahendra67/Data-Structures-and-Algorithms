#include<iostream>
#include<bits/stdc++.h>
//N-Queens II Leetcode 52

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
Placing 1 queen at each row -> give call to place queen at next row (from 0th column).
If you are unable to place queen -> go back (backtrack) and move the previous queen to next its next column -> then try to keep the queen in next row.
*/

/*
Q means queen is placed at that grid cell.
. means the grid cell is empty
*/
class Solution {
public:
    bool isItSafe(vector<string>& board, int cr, int cc){
        int row = cr;
        int col = cc;
        
        //Check vertically up
        while(row >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
        }
        
        row = cr;
        
        //Check diagonally left up
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        
        row = cr;
        col = cc;
        
        //Check diagonally right up
        while(row >= 0 && col < board.size()){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        
        //If it reaches here, means queen is safe to place
        return true;
    }
    
    int placeQueen(vector<string>& board, int row){
        //Base cases
        if(row == board.size()){
            //All queens have been placed according to condition
            return 1;
        }
        
        int count = 0;
        
        //work
        for(int col=0; col<board.size(); col++){
            //If it is safe, then only place the queen
            if(isItSafe(board, row, col) == true){
                board[row][col] = 'Q';
                //Now, try to place the queen in next row
                count += placeQueen(board, row+1);
                //Once, the call comes back remove the queen that was placed earlier
                board[row][col] = '.';
            }
        }
        
        return count;
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        return placeQueen(board, 0);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/