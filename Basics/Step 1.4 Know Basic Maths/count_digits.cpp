#include<iostream>
#include<cmath>
#include<string>
//Count digits
using namespace std;

int main(){
    int num =199;

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach 1
    //Divide the number till it becomes zero, and increase count per step
    int num1=num;
    int count=0;
    while(num1!=0){
        num1 = num1/10;
        count++;
    }
    cout<<"Count using approach 1: "<<count<<endl;

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach 2
    //Using log base 10 method
    //log base 10 of any number gives it's (no. of digits-1)
    //log base 10 of 100 gives 2, log base 10 of 120 gives 2.something
    //log10 function comes in cmath library
    int count2 = (log10(num))+1;
    cout<<"Count using approach 2: "<<count2<<endl;

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach 3
    //Convert integer to string, then use the length method
    string s = to_string(num);
    int count3 = s.length();
    cout<<"Count using approach 3: "<<count3;

    /*----------------------------------------------------------------------------------------------------------------------------------*/
    
    return 0;
}