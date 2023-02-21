#include<iostream>
#include<bits/stdc++.h>
//N-Queens Leetcode 51

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each 
other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a 
queen and an empty space, respectively.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
First, try to place a queen in each row(start from placing from the left most column).
-> then give a cell to place another queen in next row.
If you are not able to place a queen in any cell of a certain row, go back and move the queen in the above row to its next column. Then check if you can place a queen in next row.

Start by placing queens in each grid cell(all ways). Then apply given condition.
*/
class Solution {
public:
    //Check if queen is safe to place
    /*
    Whenever we are placing a queen, all the rows below the current row will be empty as 
    no call to place queen in the below rows has been called. Hence, we only need to check 
    above the current row.
    */
    bool isQueenSafe(vector<vector<string>>& board, int cr, int cc){
        //Check vertically upwards
        int row = cr;
        int col = cc;
        
        while(row >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
        }
        
        //Set row back to original current row
        row = cr;
        
        //Check diagonally left upwards
        while(row >= 0 && col >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
            col--;
        }
        
        //Set row and col back to original current row and col
        row = cr;
        col = cc;
        
        //Check diagonally right upwards
        while(row >= 0 && col <= board.size()-1){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
            col++;
        }
        
        
        //If it reaches here, means it must be safe to place queen at that grid cell
        return true;
    }
    
    void placeQueen(vector<vector<string>>& board, int row, vector<vector<string>>& ans){
        //Base case
        if(row == board.size()){
            //If it is able to place all queen such that they dont attack each other
            //then we have found an arrangement acc. to condition
            
            //Putting the board into format of vector<string>
            vector<string> temp;
            //iterating over rows
            for(int i=0; i<board.size(); i++){
                string tempstr;
                //iterating over col
                for(auto it: board[i]){
                    tempstr += it;
                }
                temp.push_back(tempstr);
            }
            
            ans.push_back(temp);
            return;
        }

        //Place single queen in a row (one column at a time)
        for(int c = 0; c<board.size(); c++){
            //Only place the queen if it is safe
            if(isQueenSafe(board, row, c)){
                //Place a queen -> give call to place queen in next row
                board[row][c] = "Q";
                placeQueen(board, row+1, ans);
                //Remove queen from current grid cell -> move it to next column
                board[row][c] = ".";
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string> (n, "."));
        
        vector<vector<string>> ans;
        
        placeQueen(board, 0, ans);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//2nd approach:Take and not take approach
/*
For every grid cell, there are 2 possible ways: either a queen is in that cell or it is not in that cell.

Only try to place the queen if it is safe: Check vertically upwards, diagonally left up and diagonally right up, and on the left of current grid cell's row.

Since, we are giving take call first then not take call -> queens will exist before the current grid cell.(hence, we only need to check the before grid cells.)
*/
class Solution {
public:
    bool isItSafe(vector<string>& board, int cr, int cc){
        int row = cr;
        int col = cc;
        
        //Check vertically upwards
        while(row >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
        }
        
        row = cr;
        
        //Check diagonally up (left)
        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        
        row = cr;
        col = cc;
        
        //Check diagonally up (right)
        while(row >= 0 && col <= board.size()){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        
        row = cr;
        col = cc;
        
        //Check in same row (left of current grid cell) -> hence check the columns of the same row(left of current cell)
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        
        //If it reaches here, it is safe to place the queen
        return true;
    }
    
    void placeQueen(vector<string>& board, int row, int col, vector<vector<string>>& ans, int count){
        //Base cases
        //If it goes out of bound for column index
        if(col == board.size()){
            //Go to next row first column
            row++;
            col=0;
        }
        
        //For row: Out of bound case
        if(row == board.size()){
            //Check if n queens have been placed yet. If yes, push it into ans
            if(count == board.size()){
                ans.push_back(board);
            }
            return;
        }
        
        //take
        //Only take/place if it is safe to place
        if(isItSafe(board, row, col) == true){
            board[row][col] = 'Q';
            //Also, pass the incremented count value
            // placeQueen(board, row, col+1, ans, count+1);
            
            //Instead of giving call to next column
            /*We know that if we place a queen in a row, we can't place another queen in same row.
            No need to give call to other columns of same row. Give call to next row first column*/
            placeQueen(board, row+1, 0, ans, count+1);
            
            //Remove the queen placed
            board[row][col] = '.';
        }
        
        //not take
        placeQueen(board, row, col+1, ans, count);
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string (n, '.'));
        
        vector<vector<string>> ans;
        
        //Count of queens placed so far
        int count = 0;
        
        //Start from first grid cell
        placeQueen(board, 0, 0, ans, count);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/