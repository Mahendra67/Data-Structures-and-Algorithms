#include<iostream>
#include<bits/stdc++.h>
//Longest common subsequence Leetcode 1143
/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

/*BRUTE FORCE APPROACH*/
//Find all subsequences of both strings, store in vector, then return the max length of common subsequence word. 
//If doesn't exists, return 0

class Solution {
public:
    void findsubsequence(int index, string text, string s, vector<string>& t, int size){
        if(index == size){
            t.emplace_back(s);
            return;
        }
        
        //take
        findsubsequence(index+1, text, s+text[index], t, size);
        
        //not take
        findsubsequence(index+1, text, s, t, size);
        
        return;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        //BRUTE FORCE APPROACH
        //Find all subsequences of both strings, store in vector, then return the max length of common subsequence word. If doesn't exists, return 0
        
        vector<string> t1,t2;
        
        int size1 = text1.length();
        int size2 = text2.length();
        
        string s1,s2;
        
        findsubsequence(0, text1, s1, t1, size1);
        
        findsubsequence(0, text2, s2, t2, size2);
        
        int max_length = 0;
        
        for(auto it: t1){
            for(auto it2: t2){
                if(it == it2){
                    int l = it.length();
                    //can't pass it.length() in max. WHY?
                    max_length = max(max_length, l);
                }
            }
        }
        
        return max_length;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}