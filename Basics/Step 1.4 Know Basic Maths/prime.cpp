#include<iostream>
#include<cmath>
//Check if a number is prime or not
//It has exactly 2 distinct factors (1 and itself)
//1 and 0 are not prime numbers

using namespace std;

bool approach1(int num){
    for(int i = 2; i<num ; i++){
        if(num % i == 0){
            return false;
        }
    }
    //For 1 and 0 edge case
    if(num == 1 || num ==0){
        return false;
    }else{
        return true;
    }
}

bool approach2(int num){
    int div = sqrt(num);
    for(int i =2; i<=div ; i++){
        if(num % i == 0){
            return false;
        }
    }
    //For 1 and 0 edge case
    if(num == 1 || num ==0){
        return false;
    }else{
        return true;
    }
}

int main(){
    int num = 53;

    //Approach 1 
    cout<<"Approach 1 : "<<approach1(num)<<endl;

    //Appraoch 2
    cout<<"Appraoch 2 : "<<approach2(num)<<endl;
    return 0;
}