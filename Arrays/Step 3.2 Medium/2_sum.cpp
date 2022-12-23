#include<iostream>
#include<bits/stdc++.h>
//2 sum
//Given an array of intergers nums and an integer target, return indices of the two numbers such that they add up to target
//Exactly one solution 
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<int> indices;
    
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                indices.push_back(i);
                indices.push_back(j);
                break;
            }
        }
    }
    
    return indices;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

vector<int> twoSum2(vector<int>& nums, int target) {
    //Using hash map
    unordered_map<int,int> mpp;

    for(int i=0;i<nums.size();i++){
        int t = target-nums[i];
        if(mpp.find(t)!=mpp.end()){
            return {i,mpp[t]};
        }
        
        mpp[nums[i]] = i;
    }
    return {-1,-1};
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    //Approach 1
    //O(n^2)
    vector<int> index = twoSum(nums,target);

    //Appraoch 2
    //O(n)
    vector<int> index2 = twoSum2(nums,target);

    for(auto it:index2){
        cout<<it<<"\t";
    }
    return 0;
}