#include<iostream>
#include<bits/stdc++.h>
//Combinations Leetcode 77

/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, vector<int>& temp, int count, vector<int>& temp1){
        //Base cases
        
        if(temp1.size() == count){
            ans.push_back(temp1);
            return;
        }
        
        if(idx == temp.size()){
            return;
        }
        
        //take
        temp1.push_back(temp[idx]);
        helper(idx+1, temp, count, temp1);
        
        //not take
        temp1.pop_back();
        helper(idx+1, temp, count, temp1);
        
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        
        for(int i=1; i<=n; i++){
            temp.push_back(i);
        }
        
        vector<int> temp1;
        helper(0, temp, k, temp1);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/