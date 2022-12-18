#include<iostream>
#include<bits/stdc++.h>
//Print from N to 1 in linear fashion
using namespace std;

void count(int m){
    if(m==0){
        return;
    }
    cout<<m<<" ";
    m--;
    count(m);
}

int main(){
    count(9);
    return 0;
}