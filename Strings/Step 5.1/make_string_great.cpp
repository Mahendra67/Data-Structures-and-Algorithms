#include <iostream>
#include<cstdlib>
#include<bits/stdc++.h>
//1544 LeetCode
//Make the strings great
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

string makeGood(string s) {
    //Using stack 
    stack<char> st;
    //Since we also need to return string
    string s2;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
            //String
            s2 += s[i];
            continue;
            //Since we need it to go to next iteration and not given condition
        }
        if(std::abs(st.top()-s[i])==32){
            st.pop();
            //For string
            s2.erase(s2.end()-1);
        }else{
            st.push(s[i]);
            //For string
            s2 += s[i];
        }
    }
    return s2;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    //Approach 1: Using Stack
    /*
    If empty, add the first char to stack. (then continue)
    Now, check if stack's top is lower or upper of given char, if yes, pop from stack
    If no, then add the char to the stack.
    To get the 'good' string back, use one more string.
    Do, the same approach for string too, if stack's top is lower or upper of given char, then remove the last char from string.
    If not, concanate the current char to the new string.
    */
    return 0;
}
