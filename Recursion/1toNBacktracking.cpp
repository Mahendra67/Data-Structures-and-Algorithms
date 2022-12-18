#include<iostream>
#include<bits/stdc++.h>
//Print 1 to N but by backtracking
using namespace std;

void count(int m){
    if(m<1){
        return;
    }
    //Backtracking mai pehle recursive call, phir baad mai work
    count(m-1);

    cout<<m<<" ";
}

int main(){
    count(8);
    return 0;
}