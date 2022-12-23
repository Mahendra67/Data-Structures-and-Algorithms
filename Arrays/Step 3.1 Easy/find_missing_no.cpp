#include<iostream>
#include<bits/stdc++.h>
//Find the missing number in an array of numbers containing 1 to n (except 1 number)
using namespace std;

void display(int arr[],int size){
        //Can't use sizeof here
        // int size = sizeof(arr)/sizeof(int);
        for(int i=0; i<size; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

int main(){
    int arr[] = {4,6,5,7,9,8,2,1,0};
    int n = sizeof(arr)/sizeof(int);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach 1
    //Sort the current array
    //Check if a[i] = a[i+1]+1 doesnt exist -> return a[i]+1
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]+1){
            cout<<arr[i]+1;
            break;
        }
    }

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach 2
    //Using XOR 
    //Take XOR of every element of array
    //Take XOR of every element from 0 to n
    //Take XOR of first and 2 


    //Approach 3
    //Missing number = (Sum of elements from 1 to n) - (Sum of elements of array)
    return 0;
}