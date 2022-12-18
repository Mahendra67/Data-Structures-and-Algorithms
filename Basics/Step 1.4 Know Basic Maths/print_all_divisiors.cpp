#include<iostream>
#include<cmath>
//Print all divisiors of a number
using namespace std;

void approach1(int num){
    for(int i=1;i<=num;i++){
        if(num % i == 0){
            cout<<i<<"\t";
        }
    }
}

void approach2(int num){
    int div = sqrt(num);
    for(int i=1 ; i <= div ; i++){
        if(num % i == 0){
            cout<< i << "\t" << num/i << "\t";
        }
    }
}

int main(){
    int num = 63;

    //Approach 1
    cout<<"Appraoch 1 : ";
    approach1(num);
    cout<<endl;

    //Approach 2 
    cout<<"Approach 2 : ";
    approach2(num);
    cout<<endl;
    return 0;
}