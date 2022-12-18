#include<iostream>
//1047 Leetcode
/*
Remove All Adjacent Duplicates In String
*/
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string s2;
        for(int i=0;i<s.length();i++){
            if(s2.empty()){
                s2+=s[i];
                continue;
            } 
            if(*(s2.rbegin())==s[i]){
                s2.pop_back();
            }else{
                s2+=s[i];
            }
        }
        return s2;
    }
};

int main(){
    

    //Approach 1 : using string
    /*Traverse through the string, in starting add first char to string and then skip that iteration.
    Then check, if the last char of new string is equal to the current_index char of original string.
    If yes, then remove the char from string. 
    If no, then add that char to new string
    */
    return 0;
}