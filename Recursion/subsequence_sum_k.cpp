#include<iostream>
#include<bits/stdc++.h>
//Print the subsequence whose sum is k

/*
Only check the condition if the subsequence has been formed. (start_idx >= size)
*/
using namespace std;

void subsequence(int start_idx,vector<int>& temp,int sum,int k,int size,vector<int> arr){
    //Base condition
    if(start_idx >= size){
        //Since, it reached this condition, this means subsequence is already formed, hence check for condition
        //Sum if equal to k
        if(sum == k){
            for(int i = 0; i<temp.size(); i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
            return;
        }

        //If the given subsequence is not equal to k
        return;
    }  

    //Take 
    temp.push_back(arr[start_idx]);

    //Take call
    //Since we are taking the element, the sum will be increased by that element
    subsequence(start_idx+1, temp, sum+arr[start_idx], k, size, arr);

    //Not take
    temp.pop_back();

    //Not take call
    //Since, we are not taking the element, the sum will remain same
    subsequence(start_idx+1, temp, sum, k, size, arr);
}


int main(){
    int start_idx = 0;
    vector<int> temp;
    vector<int> arr = {2,3,5,2,5,1,9};
    int k = 9;
    int sum = 0;
    int size = arr.size();

    subsequence(start_idx,temp,sum,k,size,arr);

    return 0;
}