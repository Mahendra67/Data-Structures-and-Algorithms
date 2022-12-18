#include<iostream>
#include<bits/stdc++.h>
//Print name 5 times 
using namespace std;

void name(int& count){
    if(count==5){
        return;
    }
    cout<<"Mahendra ";
    name(++count);
}

int main(){
    int count=0;
    name(count);
    return 0;
}