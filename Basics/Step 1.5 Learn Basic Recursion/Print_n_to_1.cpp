#include<iostream>

using namespace std;

void recursive(int i,int num){

    if(i>num){
        return;
    }

    recursive(i+1,num);
    cout<<i;
}

int main(){
    int num = 6;
    recursive(1,num);
    return 0;
}