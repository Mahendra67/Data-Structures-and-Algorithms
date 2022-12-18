#include<iostream>
#include<cmath>
//Check if a given number is armstrong or not
//Approach 1
//Count the no of digits, and then find the sum of (digits raised to power of no. of digits)
//If the sum is equal to the original number, then it is armstrong number.
using namespace std;

bool armstrong(int num){
    //First count the digits
    int count = (log10(num))+1;

    int original = num;
    int rem;
    int sum=0;
    while(num!=0){
        rem = num % 10;
        sum = sum + pow(rem,count);
        num = num / 10;
    }
    return (original==sum);
    return false;
}


int main(){
    int num = 153;
    if(armstrong(num)==true){
        cout<<"Armstrong number";
    }else{
        cout<<"Not Armstrong number";
    }
    return 0;
}