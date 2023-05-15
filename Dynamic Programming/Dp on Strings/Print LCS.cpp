#include<bits/stdc++.h>
//Print Longest Common Subsequence

/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return empty string.

A subsequence of a string is a new string generated from the original string with some 
characters (can be none) 
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

string lcsMS(int i1, int i2, string& text1, string& text2, const int& n1, const int& n2, 
    vector<vector<string>>& dp){
    //Base cases
    if(i1 == n1 || i2 == n2){
        return "";
    }

    if(dp[i1][i2] != ""){
        return dp[i1][i2];
    }

    string ans = "";
    if(text1[i1] == text2[i2]){
        ans = text1[i1] + lcsMS(i1+1, i2+1, text1, text2, n1, n2, dp);
    }else{
        string movei1 = lcsMS(i1+1, i2, text1, text2, n1, n2, dp) + "";
        string movei2 = lcsMS(i1, i2+1, text1, text2, n1, n2, dp) + "";
        //string having the larger size will be stored in dp
        int s1 = movei1.size();
        int s2 = movei2.size();
        ans = (s1 > s2)? movei1 : movei2;
    }

    return dp[i1][i2] = ans;
}

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation

/*
TC    :
SC    :
*/

string lcsTBS(string& text1, string& text2){
    int n1 = text1.size();
    int n2 = text2.size();
    
    vector<vector<string>> dp(n1+1, vector<string> (n2+1, ""));
    //Each grid cell dp[i][j] represent the lcs b/w string from index i to n1(in text1) and string from index j to n2(in text2)
    
    //Base cases
    for(int i=0; i<n2; i++){
        dp[n1][i] = "";
    }
    for(int i=0; i<n1; i++){
        dp[i][n2] = "";
    }
    
    //In recurrence relation, we can observe that for filling grid[i][j] -> it is dependent of cell just below it, cell that is just right to it and diagonally right cell.
    //And since the last row is filled by the base case -> the filling for row will br from bottom to up(n1 to 0)
    //Also the last column is filled by the base case -> the filling for columns will bee from right to left(n2 to 0)
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            string ans = "";
            if(text1[i] == text2[j]){
                ans = text1[i] + dp[i+1][j+1];
            }else{
                string movei = dp[i+1][j];
                string movej = dp[i][j+1];
                int s1 = movei.size();
                int s2 = movej.size();
                ans = (s1>s2)? movei : movej; 
            }
            
            dp[i][j] = ans;
        }
    }
    
    return dp[0][0];
}

/*-----------------------------------------------------------------------------------------------------------*/