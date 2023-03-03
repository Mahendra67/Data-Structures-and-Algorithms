#include<iostream>
#include<bits/stdc++.h>
// #include<string>
//String Compression Leetcode 443

/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input 
character array chars. Note that group lengths that are 10 or longer will be split into multiple 
characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        
        int n = chars.size();
        int count = 1;
        //Add the first char
        s += chars[0];
        
        for(int i=0; i<n-1; i++){
            if(chars[i] == chars[i+1]){
                count++;
                
                //At second last index : if char is same e.g. c c
                if(i == n-2 && count > 1){
                    s += to_string(count);
                }
            }else{
                if(count > 1){
                    //prev count
                    s += to_string(count);
                }
                
                //Add the next char into the string
                s += chars[i+1];
                count = 1;
            }
        }
        
        
        //Now update the input array
        int m = s.length();
        
        for(int i=0; i<m; i++){
            chars[i] = s[i];
        }
        
        return m;
    }
};


/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Constant space solution : Improved code quality
class Solution {
public:
    void AddDigits(vector<char>& chars, int& p, int& p1, int& p2, int& count, string& temp){
        p++;
        if(count > 9){
            temp = to_string(count);
            for(int i=0; i<temp.size(); i++){
                chars[p] = temp[i];
                p++;
            }
        }else if(count > 1){
            chars[p] = count + '0';
            p++;
        }  
    }
    
    int compress(vector<char>& chars) {
        int count = 1;
        
        //3 pointers
        int p = 0; //main pointer for updating
        int p1 = 0; //pointers for comparing
        int p2 = 1;
        
        int n = chars.size();
        
        //Edge case : If only one character
        if(n == 1){
            return 1;
        }
        
        string temp;
        //temp can have at max 4 characters(constraints:2000 characters are given)->O(1)space
        //this is for in case, length of consecutive repeating characters become greater than 9
        
        while(p2<n){
            if(chars[p1] == chars[p2]){
                count++;
                p1++;
                p2++;
            }else{
                //Add digits
                AddDigits(chars, p, p1, p2, count, temp);
                
                chars[p] = chars[p2];
                
                //Reset count
                count = 1;
                p1++;
                p2++;
            }
            
            //If p2 goes out of bound
            if(p2 == n){
                AddDigits(chars, p, p1, p2, count, temp);
            }
        }
        
        return p;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/