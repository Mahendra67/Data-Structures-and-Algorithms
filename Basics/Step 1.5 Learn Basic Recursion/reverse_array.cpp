#include<iostream>
#include<algorithm>
//Reverse the array 
using namespace std;

void recursion(int arr3[],int start, int end){
    //Base
    if(start>end){
        return;
    }
    //Work
    swap(arr3[start],arr3[end]);
    //Recursive call
    recursion(arr3,start+1,end-1);
}

int main(){
    int arr[] = {3,4,6,1,3,5,667,3};
    int arr3[] = {3,4,6,1,3,5,667,3};
    int arr4[] = {3,4,6,1,3,5,667,3};

    //Approach 1
    //Use an extra array and store element of arr in reverse order
    int size = sizeof(arr)/sizeof(int);
    int arr2[size];

    for(int i = 0; i<size ;i++){
        arr2[i] = arr[size-1-i];
    }
    
    for(int i =0; i<size ;i++){
        cout<<arr2[i]<<"\t";
    }

    cout<<endl;

    //Approach 2
    //Swapping only half way without using extra space
    for(int i = 0; i<(size/2) ;i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
    //Print
    for(int i =0; i<size ;i++){
        cout<<arr[i]<<"\t";
    }

    cout<<endl;

    //Appraoch 3
    //Recursively

    recursion(arr3,0,size-1);
    //Print
    for(int i =0; i<size ;i++){
        cout<<arr3[i]<<"\t";
    }

    cout<<endl;

    //Approach 4
    //Using reverse function
    reverse(arr4,arr4+size);
    //Print
    for(int i =0; i<size ;i++){
        cout<<arr4[i]<<"\t";
    }
    
    return 0;
}