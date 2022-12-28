#include<iostream>
#include<bits/stdc++.h>
//Longest Common Prefix LeetCode 14
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
using namespace std;

/*-------------------------------------------------------------------------------------------------------------*/

//Optimal Appraoch : O(m*n) , here n-> no. of strings in that vector, and m is length of 1st word of vector
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        
        //Set the first word as prefix
        string prefix = strs[0];
        
        //Now, start checking from 2nd word
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<prefix.size(); j++){
                //Only compare if j values are equal or smaller than of comparing string size
                if(j<=strs[i].size() && prefix[j] != strs[i][j]){
                    prefix = prefix.substr(0,j);
                }
            }
        }
        
        return prefix;
    }
};

/*-------------------------------------------------------------------------------------------------------------*/

//Using sort, Time Complexity : O(m*nlogn)
/*
Sort the string vector. This will group similar words together.
If a character is common throughout the vector of strings it will appear at all words.
Hence, if prefix characters exists in both first and last word, that means it exists throughout
the vector.

If it finds a non-common character, it will be sorted alphabetically. 
Now, the first word and the last word of the vector will have the maximum difference.
Return the common prefix of the first and last word.

e.g. 
["flower","flow", "fl","flight"]

After sorting:
["fl", "flight", "flow", "flower"]

Common prefix of first and last word : "fl"

e.g.
["hello", "abcd", "abch"]

After sorting:
["abcd", "abch", "hello"]

Common prefix of first and last word : ""

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        //Sort the vector of strings
        sort(strs.begin(), strs.end());
        
        //Only check till the smaller word index
        int size1 = strs[0].size();
        int size2 = strs[strs.size()-1].size();
        int minIndex = min(size1, size2);
        
        //Now check for common prefix characters in first and last word
        //For understanding: take variables for first and last word
        string first = strs[0];
        string last = strs[strs.size()-1];
        for(int i=0; i<minIndex; i++){
            if(first[i] == last[i]){
                //Add common prefix characters to string
                ans += first[i];
            }else{
                break;
            }
        }
        
        return ans;
    }
};

/*-------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}