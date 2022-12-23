#include<iostream>
//Left rotate an array 

//Note
//https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/
//You can't use sizeof while passing array as parameter(since it treats the passed array parameter as pointer)
//You can use sizeof in main (for arrays)
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

void approach1(int arr[],int size){
    int temp = arr[0];

    //Left shift
    // int size = sizeof(arr)/sizeof(int);
    //Can't use sizeof here
    for(int i=0; i<size-1; i++){
        arr[i] = arr[i+1];
    }

    //Update the last element
    arr[size-1] = temp;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

void approach2(int arr[],int temp[],int size){
    for(int i=0 ; i<size-1 ; i++){
        temp[i] = arr[i+1];
    }
    temp[size-1] = arr[0];
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

void display(int arr[],int size){
    //Can't use sizeof here
    // int size = sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};

    int size = sizeof(arr) / sizeof(int);

    //Appraoch 1
    //Storing the first element of array in temp variable
    //Left shifting the array elements by 1
    //Then, update the last element of array to temp

    approach1(arr,size);
    //Display the array
    display(arr,size);

    //Approach 2
    //Take a second array and store elements according to one left shift
    //Manually, add the last element
    
    int temp[size];
    approach2(arr,temp,size);
    //Display thr array
    display(temp,size);

    return 0;
}