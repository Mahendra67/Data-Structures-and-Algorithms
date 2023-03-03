#include<iostream>
#include<bits/stdc++.h>
//Find Index of First Ocurrence in a String Leetcode 28

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n = haystack.size();
        int m = needle.size();
        
        //Not getting segmentation fault at haystack[n+1] to haystack[n+7]????
        //cout<<haystack[n+1]<<endl;

        //s = "hello" then s[5] = '\0'.  But why no seg fault at s[6] in Leetcode compiler
        
        int firstOccur = -1;
        char firstChar = needle[0];
        int tempIdx = 0;
        
        for(int i=0; i<n; i++){
            if(firstChar == haystack[i]){
                tempIdx = i;
                for(int j=0; j<m; j++){
                    //Also check validity of tempIdx
                    if(tempIdx == n || haystack[tempIdx] != needle[j]){
                        break;
                    }
                    //If it reaches here, it means the char is equal at index i in haystack, j in needle
                    //If last index is also same, first occurence found
                    if(j == m-1){
                        firstOccur = i;
                        break;
                    }
                    
                    //Increase temp index to continue search in word1
                    tempIdx++;
                }
                
                //Check if you found an ans
                if(firstOccur != -1){
                    break;
                }
            }
        }
        
        return firstOccur;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/