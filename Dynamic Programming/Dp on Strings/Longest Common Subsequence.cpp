#include<bits/stdc++.h>
//Longest Common Subsequence Leetcode 1143

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common 
subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

//Memoization

/*
TC    :
SC    :
*/

int lcs(int i1, int i2, string& text1, string& text2, const int& n1, const int& n2, 
    vector<vector<int>>& dp){
        //Base cases
    if(i1 == n1 || i2 == n2){
        return 0;
    }

    if(dp[i1][i2] != -1){
        return dp[i1][i2];
    }

    int ans = 0;
    if(text1[i1] == text2[i2]){
        ans = lcs(i1+1, i2+1, text1, text2, n1, n2, dp) + 1;
    }else{
        int movei1 = lcs(i1+1, i2, text1, text2, n1, n2, dp) + 0;
        int movei2 = lcs(i1, i2+1, text1, text2, n1, n2, dp) + 0;

        ans = max(movei1, movei2);
    }

    return dp[i1][i2] = ans;
}

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation 

/*
TC    :
SC    :
*/

int lcsTB(string& text1, string& text2){
    int n1 = text1.size();
    int n2 = text2.size();
    
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
    //Each grid cell dp[i][j] represent the lcs b/w string from index i to n1(in text1) and string from index j to n2(in text2)
    
    //Base cases
    for(int i=0; i<n2; i++){
        dp[n1][i] = 0;
    }
    for(int i=0; i<n1; i++){
        dp[i][n2] = 0;
    }
    
    //In recurrence relation, we can observe that for filling grid[i][j] -> it is dependent of cell just below it, cell that is just right to it and diagonally right cell.
    //And since the last row is filled by the base case -> the filling for row will br from bottom to up(n1 to 0)
    //Also the last column is filled by the base case -> the filling for columns will bee from right to left(n2 to 0)
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            int ans = 0;
            if(text1[i] == text2[j]){
                ans = dp[i+1][j+1] + 1;
            }else{
                int movei = dp[i+1][j];
                int movej = dp[i][j+1];
                ans = max(movei, movej);
            }
            
            dp[i][j] = ans;
        }
    }
    
    return dp[0][0];
}

/*-----------------------------------------------------------------------------------------------------------*/