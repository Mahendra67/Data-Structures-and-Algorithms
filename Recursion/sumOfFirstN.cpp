#include<iostream>
#include<bits/stdc++.h>
//Find sum of first N numbers
//2 methods:
//a. Parameterized method
//b. Functional method
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Parameterized
void sum(int i,int sum1){
    if(i<1){
        cout<<sum1;
        return;
    }
    sum(i-1,sum1+i);
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Functional method
int fun(int m){
    if(m==0){
        return 0;
    }
    return m + fun(m-1);
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    sum(5,0);

    cout<<endl;

    cout<<fun(5);
    return 0;
}