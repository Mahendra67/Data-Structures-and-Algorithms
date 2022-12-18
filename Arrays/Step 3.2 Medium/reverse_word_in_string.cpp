#include<iostream>
#include<bits/stdc++.h>
//151 LeetCode
/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
using namespace std;

//Approach 1
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        
        string ans;
        while(i<n){
            //First find the first char
            //First,check if it is in bound, then only try to access the element
            while(i<n && s[i]==32){
                i++;
            }
            //Now, i has the first char of string
            //Now, find the last char of the word
            int j = i+1;
            while(j<n && s[j]!=32){
                j++;
            }
            
            //So that we dont get any leading spaces
            //eg "  hello world  "
            //                  |  |
            //                  i  j
            //This will add leading space to the front, hence to avoid it we gave following condition
            if(j>n){
                break;
            }
            //Now, j index has the first space after the first word of string
            //In substr:
            //First argument is starting index, second is no. of characters
            /*hello 
              |     |
              i     j
              No. of characters between i and j is (j-i)*/
            string s1 = s.substr(i,j-i);
            if(ans.length()==0){
                //Since we dont want any trailing space in end result
                ans += s1;
            }else{
                ans = s1 + " " + ans;
            }
            //Now update i index to next index of the first space we found after the word(line 19)
            i = j+1;
        }
        return ans;
    }
};

int main(){
    

    //Appraoch 1: O(n) space
    /*
    Find the starting and ending index of word. Store the substring in temp string.
    Add to new string such that the temp string is suffix of new string.
    ans = temp + " " + ans;
    */
    return 0;
}