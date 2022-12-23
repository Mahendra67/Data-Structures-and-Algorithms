#include<iostream>
#include<bits/stdc++.h>

/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

*/

using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

bool isAnagram1(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    if(s==t){
        return true;
    }
    return false;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    string s = "hello";
    string t = "olhel";
    
    //Approach 1
    //Sort both array and check if they are same, if yes return true;
    cout<<isAnagram1(s,t);
    cout<<endl;

    //Approach 2
    return 0;
}