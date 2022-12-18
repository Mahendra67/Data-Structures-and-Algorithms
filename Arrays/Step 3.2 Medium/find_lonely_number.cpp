#include<iostream>
#include<bits/stdc++.h>
//2150 Leetcode
/*
ou are given an integer array nums. 
A number x is lonely when it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.

Return all lonely numbers in nums. You may return the answer in any order.
*/
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        //Add every element into hashmap
        for(auto it:nums){
            mpp[it]++;
        }
        
        //Check for given condition
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==1 && mpp[nums[i]+1]==0 && mpp[nums[i]-1]==0){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};

int main(){
    

    //Approach 1 : Using hashmap
    /*
    Store all the elements of the given vector along with its frequency in a hashmap.
    Now, traverse through the original vector and check if the given element frequency is equal to 1 and 
    element+1 and element-1 doesnt exist in the hashmap. If yes, then add that element to the vector.
    */
    return 0;
}