#include<iostream>
//Given a number n, print the fibonacci numbers upto nth term
using namespace std;

int recursion(int num){
    if(num<=1){
        return num;
    }
    int last = recursion(num-1);
    int second_last = recursion(num-2);
    return last+second_last;
}

int recursion2(int num, int first, int second){
    cout<<first<<"\t";
    if(num<=1){
        return first+second;
    }
    //The first term becomes second
    //And the second term becomes first + second
    recursion2(num-1,second,first+second);
    //Zero signifies program completetion
    return 0;
}

int main(){
    int num = 6;

    //Appraoch 1
    //Using recursion to find fibonacci number
    cout<<recursion(num);

    cout<<endl;

    //Approach 2
    //Brute force
    int first = 0;
    int second = 1;
    for(int i=0; i<num;i++){
        cout<<first<<"\t";
        int temp = second;
        second = first + second;
        first = temp;
    }

    cout<<endl;

    //Aproach 3
    //Using recursion to find the fibonnaci sequence
    recursion2(num,0,1);
    return 0;
}