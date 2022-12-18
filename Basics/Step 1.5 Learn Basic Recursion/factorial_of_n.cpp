#include<iostream>

using namespace std;

int recursive(int n){

    //base
    if(n==1){
        return 1;
    }

    return n * recursive(n-1);
}

int main(){
    int num = 6;
    cout<<recursive(num);
    return 0;
}