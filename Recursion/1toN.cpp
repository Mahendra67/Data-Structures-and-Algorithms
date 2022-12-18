#include<iostream>
#include<bits/stdc++.h>
//Print linearly from 1 to n
using namespace std;

void count(int n,int m){
    if(n==m+1){
        return;
    }
    cout<<n<<" ";
    n++;
    count(n,m);
}

int main(){
    count(1,5);
    return 0;
}