#include<iostream>
#include<bits/stdc++.h>
//Single Number Leetcode 136
/*
Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.
*/
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Approach using : XOR

        /*
        A ^ A = 0
        0 ^ A = A
        A ^ B ^ A = B

        Using XOR, if 2 numbers are same, then applying XOR on those elements will return 0.
        If they are not same, and one is zero, it will return the non-zero element.
        */

        int ans = 0;
        for(auto it: nums){
            ans = ans ^ it;
        }

        return ans;
    }
};


int main(){
    
    return 0;
}