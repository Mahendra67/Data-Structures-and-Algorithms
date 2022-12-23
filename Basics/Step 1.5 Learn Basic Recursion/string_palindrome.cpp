#include<iostream>
//Check if the given string is palindrome or not
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

bool palindrome1(string s){
    for(int i=0; i<(s.length()/2); i++){
        if(s[i]!=s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

bool palindrome2(string s,int start, int end){
    //Base call
    bool pal=true;
    //To store the returned answer, deafult true
    if(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        pal = palindrome2(s,start+1,end-1);
    }
    return pal;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    string s = "HelloolleH";

    //Approach 1
    //Since string is basically an array, we check if first half is same as rev of second half
    cout<<palindrome1(s);
    
    //Approach 2
    //Using recursion, using 2 pointer approach
    cout<<palindrome2(s,0,s.length()-1);
    
    return 0;
}