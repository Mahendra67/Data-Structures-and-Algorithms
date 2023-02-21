#include<iostream>
#include<bits/stdc++.h>
//Sudoku Solver Leetcode 37

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Start from (0,0) and move column by column.
For every empty space, try to place values from 1 to 9.
If you are able to place any value, move to next column.
If you are not able to place any value(from 1-9), go back and change the previous grid cell value to another valid no.

Only place any digit if it is safe to do so.
Check if the digit is already placed in horizontal and vertical paths. Also, check in 3*3 box cells.

*/
class Solution {
public:
    vector<vector<char>> ans;

    bool isItSafe(int cr, int cc, char digit, vector<vector<char>>& board){
        //Check horizontally
        for(int col=0; col<9; col++){
            if(board[cr][col] == digit){
                return false;
            }
        }
        
        //Check vertically
        for(int row=0; row<9; row++){
            if(board[row][cc] == digit){
                return false;
            }
        }
        
        //Check in each 3*3 cell
        /*
        From any grid cell, first find the starting point/cell of the 3*3 box
        2 methods:
        1.  (row/3)*3
        2.  row - (row%3)
        Same for column index
        */
        int startRow = (cr/3) * 3;
        int startCol = (cc/3) * 3;
        //Starting from that starting cell, check within that 3*3 grid
        for(int i=startRow; i < startRow+3; i++){
            for(int j=startCol; j < startCol + 3; j++){
                if(board[i][j] == digit){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void placeDigit(int row, int col, vector<vector<char>>& board){
        //Base cases
        if(col == 9){
            row++;
            col = 0;
        }
        
        if(row == 9){
            //As we go back we will be reverting the changes made
            //Take a screenshot/store the ans formed

            ans = board;

            return;
        }
        
        //if it was already filled before
        if(board[row][col] != '.'){
            //give call to next column
            placeDigit(row, col+1, board);
            //The following shouldn't run as it only for empty locations
            //Hence, to time optimize -> return from here
            return;
        }
        
        //place digits from 1-9 : Place at empty locations
        //Check if you can place that digit 
        for(int digit=1; digit<=9; digit++){
            if(isItSafe(row, col, digit + '0', board) == true){
                //Set the digit and give call to next column

                //Adding char '0' to convert it into char num (ASCII of '0' is 48)
                //48 onwards char 1-9 starts
                board[row][col] = digit + '0';
                placeDigit(row, col+1, board);


                //In case it reaches i=9 but it is still not able to place it
                //It will backtrack, but leaves the grid cell as 9 -> whereas originally it was empty
                //Hence, after every iteration, change it back to empty
                board[row][col] = '.';
            }
        }
        
        return;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        placeDigit(0, 0, board);

        board = ans;
        
        return;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/