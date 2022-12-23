#include<iostream>
//Left rotate array by k times
using namespace std;

void display(int arr[],int size){
    //Can't use sizeof here
    // int size = sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void rotate(int arr[],int n,int k){

    k = k % n;
    if(k==0){
        return;
    }
    int temp[k];

    //Copy the last k elements to temp array
    int i = 0;
    for(int j = (n-1)-k+1 ; j<=n-1 ; j++){
        temp[i++] = arr[j];
    }

    //Shift the main array by k elements
    //Start from rightmost element(s.t. it is kth from end) to shift right by k
    //Stop at i=k-1 to avoid segmenatation fault
    for(int j = n-1 ; j>k-1 ; j--){
        arr[j] = arr[j-k];
    }

    //Now add the temp array to start of main array
    for(int i = 0; i<k ; i++){
        arr[i] = temp[i];
    }
}

void reverse(int arr[],int start, int end){
    while(start<=end){
        //Swap 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    int k =3;
    int size = sizeof(arr)/sizeof(int) ; 

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach1
    //Copy the last k elements to temp array
    //Shift the remaining elements right side by k times
    //Add the temp array to starting of main array
    rotate(arr,size,k);

    //Display
    display(arr,size);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Approach2
    //Using reversal algorithm
    //Reverse upto the kth element from the last
    reverse(arr2,size-k,size-1);
    //Now reverse the first n-k elements 
    reverse(arr2,0,size-k-1);
    //Now reverse the whole array
    reverse(arr2,0,size-1);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    //Display
    display(arr2,size);

    return 0;
}