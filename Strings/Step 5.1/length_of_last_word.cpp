#include<iostream>
//Find the length of last word
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

int lengthOfLastWord(string s) {
    int start = 0;
    int end = 0;
    for(int i=s.length()-1; i>=0; --i){
        if(s[i]!=32){
            end = i;
            break;
        }
    }
    
    for(int i=end; i>=0; --i){
        if(s[i]==32){
            start = i;
            break;
        }
        //In case the index reaches zero but doesnt find space 
        if(i==0){
            start=-1;
        }
    }
    return end-start;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    string s= "afesggsge";
    cout<<lengthOfLastWord(s);
    return 0;
}