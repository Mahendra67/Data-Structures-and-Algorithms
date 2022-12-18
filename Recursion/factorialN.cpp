#include<iostream>
#include<bits/stdc++.h>
//Factorial of n using functional recursion

using namespace std;

int fact(int m){
    if(m==1){
        return 1;
    }
    return m * fact(m-1);
}

//Parameterized

void fact2(int m,int f){
    if(m==1){
        cout<<f;
        return;
    }
    fact2(m-1,f*m);
}

int main(){
    cout<<fact(3);

    cout<<endl;

    fact2(3,1);
    return 0;
}