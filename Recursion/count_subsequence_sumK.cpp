#include<iostream>
#include<bits/stdc++.h>
//Count the number of subsequences whose sum is equal to k
using namespace std;
//No need to take extra temp vector since we only need no. of subsequence and we dont want to print the subsequence

int sub(int start_idx, vector<int> arr, int size, int k, int sum){
    if(start_idx >= size){
        if(sum == k){
            return 1;
        }
        return 0;
    }

    //take
    int n1 = sub(start_idx+1 , arr, size, k, sum+arr[start_idx]);

    //Not take
    int n2 = sub(start_idx+1 , arr, size, k, sum);

    return n1 + n2;
}

int main(){
    vector<int> arr = {2,3,5,6,3,6};
    int size = arr.size();
    int start = 0;
    int k = 12;
    int sum = 0;

    int count = sub(start,arr,size,k,sum);
    cout<<"No of subsequence whose sum is equal to k is :"<<count;
    return 0;
}