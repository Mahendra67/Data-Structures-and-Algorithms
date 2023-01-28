#include<iostream>
#include<bits/stdc++.h>
//Partition Array into 2 subsets to minimize sum difference LeetCode 2035

/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Approach 1: Recursion -> gives TLE
Find out all the sum of possible subsets and store them in an unordered set.
Now, in the unordered set, for each element,
    find its other subset sum (total sum - 1 subset sum).
Find the min of difference of sum of both subsets.
*/
class Solution {
public:
    //count is used to check for size of elements considered
    //we will return when considered size becomes n.  (2n is total array size)
    void Subset(int idx, vector<int>& nums, int sum, int count, unordered_set<int>& Subsum,
                int n){
        //Base case
        //Either you reach -1 index, or the size of considered elements becomes n
        if(idx < 0){
            return;
        }
        
        if(count == n){
            Subsum.insert(sum);
            return;
        }
        
        
        //take
        Subset(idx-1, nums, sum+nums[idx], count+1, Subsum, n);
        
        //not take
        Subset(idx-1, nums, sum, count, Subsum, n);
        
        return;
    }
    
    int minimumDifference(vector<int>& nums) {
        //Find the total sum of array
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        
        int n = nums.size();
        
        //Find out all the possible subsets(size: n) and store their sum in set
        unordered_set<int> Subsum;
        
        
        Subset(nums.size()-1, nums, 0, 0, Subsum, n/2);
        
        //Now, find the min difference between 2 complementary subsets
        //sub1 is sum of subset 1
        //sub2 is sum of subset 2
        int minimum = INT_MAX;
        
        for(auto sub1: Subsum){
            int sub2 = sum - sub1;
            int diff = std::abs(sub1 - sub2);
            minimum = min(minimum, diff);
        }
        
        return minimum;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Meet in the middle approach missing

/*-----------------------------------------------------------------------------------------------------------*/