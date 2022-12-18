#include<iostream>
#include<bits/stdc++.h>
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
using namespace std;

int bruteforce(vector<int>& nums){
    int n = nums.size()/2;
    int count = 0;

    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count>n){
            return nums[i];
        }
    }
    //Assuming the array has atleast 1 element
    return nums[0];
}

int majorityElement1(vector<int>& nums) {
    int n = nums.size()/2;
    //Using hashmap
    unordered_map<int,int> mpp;
    
    //Count frequency and store in hashmap
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    
    //Checking for majority element
    for(auto it:mpp){
        if(it.second>n){
            return it.first;
        }
    }
    return nums[0];
}

int majorityElement2(vector<int>& nums) {
    int n = nums.size()/2;
    int count=1;
    //Sort the given array
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size()-1;i++){
        //Check if adjacent elements are same
        if(nums[i]==nums[i+1]){
            count++;
        }else{
            //Not same
            count = 1; 
        }
        
        //Check if count is greater than size/2
        if(count>n){
            return nums[i];
        }
    }
    //If array is of 1 element
    return nums[0];
}

int majorityElement3(vector<int>& nums){
    //Using Moore's voting algorithm
    int count = 0;
    int majority = 0;
    
    for(int i=0; i<nums.size() ;i++){
        if(count == 0){
            majority = nums[i];
        }
        
        if(majority == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    
    return majority;
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> arr1 = {1,2,1};

    //Brute Force Approach
    //Use two nested loops to find count of every element
    //If count>n/2 return that element
    cout<< bruteforce(arr);

    cout<<endl;

    //Approach 1
    //Using hashmap to record freqency and then checking if any element is more than n/2 times
    cout<< majorityElement1(arr);

    cout<<endl;

    //Approach 2
    //Sort the given array O(nlogn)
    //Initialise the count to 1
    //Check if adjacent elements are same, if yes increase count O(n)
    //else change count back to 1
    //Then check if count > n/2 , if yes return arr[i]

    //Edge case
    //If array is of 1 size
    //return the first element
    cout<< majorityElement2(arr1);

    cout<<endl;


    //Approach 3
    //Moore's Voting Algorithm O(n)

    cout<< majorityElement3(arr);
    return 0;
}