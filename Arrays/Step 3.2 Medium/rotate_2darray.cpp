#include<iostream>
#include<bits/stdc++.h>
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
*/
using namespace std;

void rotate1(vector<vector<int>>& matrix) {
    //First find transpose of matrix
    int n = matrix.size();
    for(int i = 0;i<n;i++){
        for(int j=i ;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    //Reverse each row
    for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
    }
}


void display(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};

    //Approach 1
    //Update the current 2d matrix to its transpose(swap a[j][i] by a[i][j])
    //Reverse each row
    rotate1(nums);

    display(nums);
    return 0;
}