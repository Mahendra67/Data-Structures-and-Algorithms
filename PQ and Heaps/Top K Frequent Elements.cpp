#include<iostream>
#include<bits/stdc++.h>
//Top K Frequent Elements Leetcode 347

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
Given a vector return k numbers which are the most frequent.

Approach:
Count the frequency of numbers in given array.
Now, add pair of {freq, num} into a priority queue.
Since, answers are unique, it will always be sorted according to frequncy.

Return the top elements in priority queue
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        
        //count
        for(auto &it: nums){
            mpp[it]++;
        }
        
        //vector that will store ans
        vector<int> ans;
        
        priority_queue<pair<int,int>> pq;
        
        //push the numbers along with their frequency
        for(auto &it: mpp){
            int freq = it.second;
            int num = it.first;
            pq.push({freq, num});
        }
        
        //Now, return the top k nums from the PQ
        for(int i=0; i<k; i++){
            int num = pq.top().second;
            pq.pop();
            
            ans.emplace_back(num);
        }
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/