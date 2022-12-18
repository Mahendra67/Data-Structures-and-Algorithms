#include<iostream>
//Reverse the given number
using namespace std;

int main(){
    int num = 1234;

    //Approach 1
    //Get the remainder and add it to final number while multiplying the original final number by 10.
    //Also, divide the numeber by 10 at each step
    int num2 = num;
    int reverse =0;
    while(num2!=0){
        int rem = num2 % 10 ;
        num2 /= 10;
        reverse = (reverse*10) + rem ;
    }
    cout<<"Reverse using approach 1 is : "<<reverse<<endl;

    return 0;
}