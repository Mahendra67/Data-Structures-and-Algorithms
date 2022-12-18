#include<iostream>
//Check if the given number is palindrome or not
using namespace std;

int main(){
    int num = 3456543;

    //Approach 1
    //Reverse the number and check if it same as the original number
    //Reversing the number
    int num2 = num;
    int rev = 0;
    while(num2!=0){
        int x = num2 % 10 ;
        num2 = num2 / 10 ;
        rev = (rev*10) + x ;
    }
    //Now Checking if same as original
    if(rev==num){ 
        cout<<"Palindrome number";
    }else{
        cout<<"Not palindrome";
    }
    return 0;
}