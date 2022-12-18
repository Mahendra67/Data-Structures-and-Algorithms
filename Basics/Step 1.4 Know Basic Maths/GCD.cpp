#include<iostream>
//Return the highest common divisior

using namespace std;

int main(){
    int num1=5,num2=100;

    //Approach 1 (Brute Force)
    int hcd=1;
    for(int i=1;i<=min(num1,num2);i++){
        if(((num1%i)==0) && ((num2%i)==0)){
            hcd = i;
        }
    }
    cout<<"Highest common divisor using approach 1 is : "<<hcd;
    return 0;

    //Approach 2 by eucliean theorem
}