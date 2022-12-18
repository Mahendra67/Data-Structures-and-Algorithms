#include<iostream>
//Move zeroes to the back of the array, such that the order of non-zero elements remain same
using namespace std;

void display(int arr[],int size){
    //Can't use sizeof here
    // int size = sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void approach1(int arr[],int size){
    int temp[size];

    //Add the non-zero elements
    int j = 0;
    //Count no of zeros
    int count = 0;
    for(int i = 0; i<size ;i++){
        if(arr[i]!=0){
            temp[j++] = arr[i];
        }
        if(arr[i]==0){
            count++;
        }
    }

    //Now add 'count' no. of zeroes at the back
    for(int j = size-count ; j<size ; j++){
        temp[j] = 0;
    }

    //Display the array
    display(temp,size);
}

void approach2(int arr[],int n){
    //Finding first occurence of zero
    //Default index is zero
    int first = 0;
    while(first<n){
        if(arr[first]==0){
            break;
        }
        first++;
    }

    //Now, swap if second pointer has non-zero element
    for(int second = first+1 ; second<n ; second++){
        if(arr[second] != 0){
            swap(arr[second],arr[first]);
            first++;
        }
    }

    display(arr,n);
}


int main(){
    int arr[] = {0,1,0,3,12};
    int size = sizeof(arr)/sizeof(int);

    //Approach 1
    //Using a temp array to first store non-zero elements (and count no. of zeroes in arr), then add zeros at the back
    approach1(arr,size);

    //Approach 2
    //Using 2 pointer approach, one will be i. and another i+1;
    //First find out the index of first occurence of zero
    //If arr[second pointer] is non-zero, then swap, otherwise increase another pointer by 1
    approach2(arr,size);

    return 0;
}