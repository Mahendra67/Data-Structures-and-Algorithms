#include<iostream>
#include<bits/stdc++.h>
//Print N to 1 using backtracking
using namespace std;

void count(int m,int n){
    if(m>n){
        return;
    }
    count(m+1,n);

    cout<<m<<" ";
}

int main(){
    count(1,7);
    return 0;
}