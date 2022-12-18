#include<iostream>
//Print 1 to n without using loop
using namespace std;

void recursive(int i,int n){
    if(i>n){
        return;
    }
    
    cout<< i<<"\t";

    recursive(i+1,n);
}

int main(){
    int n = 6;
    recursive(1,n);
    return 0;
}