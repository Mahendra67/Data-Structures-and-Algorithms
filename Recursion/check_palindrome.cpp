#include<iostream>
#include<bits/stdc++.h>
//Check if the given string is palindrome or not using recursion
using namespace std;

bool palindrome(string s,int i){
    if(i >= s.length()/2){
        return true;
    }
    if(s[i]!=s[s.length()-1-i]){
        return false;
    }
    return palindrome(s,i+1);
}

int main(){
    string s ="HELLOOLLEH";
    cout<<palindrome(s,0);
    return 0;
}