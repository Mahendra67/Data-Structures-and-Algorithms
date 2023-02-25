#include<iostream>
#include<bits/stdc++.h>
//Minimize deviation in an array Leetcode 1675

/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    : n*logn*logm -> n is length of nums and m is max(nums[i])
SC    : O(n)
*/

/*
We can multiply odd number by 2, and can divide even number by 2.
Observation:
Mulitplying odd number by 2 once will make it an even number.

Multiply all the odd numbers present in the array.
And if the lower bound was odd, this will maximize the lower bound.
But this will also, increase the upper bound -> which we do not need as we are looking for minimum deviation (deviation: diff between min number and max number in the array).

Also, after every operation(*by 2 and / by 2), we need the array to be in sorted order everytime we perform some operation -> as we need to find the deviation. -> Use priority queue.


Now, the max element in array has to be even. Find the deviation and perform 'divide by 2' operation on it. Before pushing it back to the pq, check if it has become the min number of the array.
e.g.
min num = 3 //current
[3,4]  -> 4/2 = 2 -> [2,4]

new min num = 2 -> now this will be used to find deviation [upperBound - 2]

Now, the max element of the array has 2 cases:
1. It is odd: You can't perform any operation on it. (As if you multipy it by 2, it will only increase the deviation ->  but we need min deviation.
Hence, if upperBound becomes odd, it will give minDeviation.

2. It is even: Same operation from line 13-16. Keep doing this until you find odd number as UpperBound.
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = 1e9;
        int mini = 1e9;
        
        int n = nums.size();
        
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            //If it is odd, multiply it by 2
            nums[i] = (nums[i]&1)? nums[i]*2 : nums[i];
            pq.push(nums[i]);
            
            //Also, since we are using PQ, we need to keep track of min value of array
            mini = min(mini, nums[i]); 
        }
        
        
        //Now, while the upperBound is even
        while(!(pq.top()&1)){
            int upperBound = pq.top();
            pq.pop();
            
            //Find the deviation
            ans = min(ans, upperBound - mini);
            
            //Since, it is even -> we can perform divide by 2
            int newNum = upperBound/2;
            //Check if it has become the min number in the pq
            mini = min(mini, newNum);
            
            //Push back the new Num
            pq.push(newNum);
        }
        
        //If the upperBound becomes odd -> can't perform * by 2 -> will only increase the deviation
        //Hence if we find odd number as upperBound -> it will give minDeviation
        
        ans = min(ans, pq.top() - mini);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/