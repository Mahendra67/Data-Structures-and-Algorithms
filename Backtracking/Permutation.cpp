#include<iostream>
#include<bits/stdc++.h>
//Permutations LeetCode

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC : n! * n
SC : O(n) + O(n)  -> one for recursive stack space, and one for keeping the picked/not picked info array.
*/

/*
Approach 1:
Consider 'n' sized array
For first position of permutation, you can pick any element from the array (n choices).
For second position, you have (n-1) choices, as you can't pick the previous chosen element,
and so on. Once you picked 'n' element, store that permutation. 
Unlike combinations, here at each step you have to pick an element.

Keep an array to check what elements have been picked and not picked.
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void permutation(vector<int>& nums, vector<int>& picked, vector<int>& temp){
        int n = nums.size();
        int m = temp.size();
        
        //Base cases
        if(n == m){
            ans.push_back(temp);
            return;
        }
        
        
        //Check the whole array for which elements have not been picked yet
        for(int i=0; i<n; i++){
            //If an element is not picked yet pick it
            if(picked[i] == 0){
                //Mark it as picked and push into temp
                picked[i] = 1;
                temp.push_back(nums[i]);
                permutation(nums, picked,temp);
                picked[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> picked(n, 0);
        vector<int> temp;
        permutation(nums, picked, temp);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//TC : n! * n
//SC : O(n) -> Recursive stack space

/*
Intuition: Every number should be at a particular index.

Approach 2: Without using extra array to store which element have not been picked yet.

Start with a pointer at zero index, and swap with itself and indices on the right of current index.

In recursion, at each step (assume i as pointer), you need to swap with all the elements on the right, and give recursive call at each swap(with pointer increased).
Loop runs from i -> n-1

e.g. 1,2,3

First call, i is at zero index. It will give 3 seperate calls
1   :   1,2,3   Swapped 0th index with itself (i = 0) -> Gives call with i = 1
2   :   2,1,3   Swapped 0th index with 1st index (i =0) -> Gives call with i = 1
3   :   3,2,1   Swapped 0th index with 2nd index(i=0) -> Gives call with i=1

1st case will cover all the permutations starting with 1.
2nd cases will cover all the permutation starting with 2.
3rd case will cover all the permutations starting with 3.

And so on. Once the pointer reaches n -> Permutation have been formed

*/
class Solution {
public:
    vector<vector<int>> ans;
    
    void permutation(int idx, vector<int>& nums){
        //Base case
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return;
        }
        
        //Loop runs from idx -> n-1 (only swap with itself and elements on the right)
        for(int i=idx; i<n; i++){
            //Swap
            swap(nums[idx], nums[i]);
            //Give next call 
            permutation(idx+1, nums);
            //Swap it back -> as we are passing it by reference
            swap(nums[idx], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(0, nums);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/