#include<iostream>
#include<bits/stdc++.h>
//Find nth fibonnaci number using recursion
using namespace std;

//Key takeaway
/*
If there are multiple recursion calls, the second one starts to give recursion call when first one completes its recursion call.
And the chain goes on.
*/

int fibb(int n){
    if(n<=1){
        return n;
    }
    return fibb(n-1)+fibb(n-2);
}

int main(){
    cout<<fibb(4);
    return 0;
}