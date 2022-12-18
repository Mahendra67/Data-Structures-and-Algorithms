#include<iostream>

using namespace std;

void recursive(int num){
    
    if(num==0){
        return;
    }

    cout<<"Name \t";
    recursive(num-1);
}

int main(){
    int num = 5;
    recursive(num);
    return 0;
}