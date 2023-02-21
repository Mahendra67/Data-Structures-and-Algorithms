#include<iostream>
#include<bits/stdc++.h>
//Count odd numbers in an interval LeetCode 1593

/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
Approach:
Find the first odd number and the last odd number in the range.

2 cases:
1. If high == low -> then check if that num is odd -> return 1
2. If you find any odd number, to find total odd nos. b/w 2 odd no = ceil(size/2)
Here, size refers to the size of array considering the first odd no. as first element
and last odd num as last element
*/
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        
        int firstOdd;
        int lastOdd;
        
        //Case 1
        if(high == low){
            if(low % 2 != 0){
                return 1;
            }else{
                return 0;
            }
        }
        
        //Case 2
        //Check if low/high is odd, if yes associate firstOdd/lastOdd with them
        //else shift one inwards
        if(low % 2 == 0){
            firstOdd = low+1;
        }else{
            firstOdd = low;
        }
        if(high % 2 == 0){
            lastOdd = high-1;
        }else{
            lastOdd = high;
        }
        
        /*
        ceil(size/2) -> wasn't working because since size is int data type, size/2 first
        converts to int then gives the argument to ceil.
        So, ceil(0) is called in case size=1.
        To avoid this typecase size/2 to float.
        */
        int size = lastOdd-firstOdd+1;
        // count = ceil((float)size/2);
        /*
        Using ceil function gives error for test case:
        800445804
        979430543
        
        Expected output:89492370
        Output: 89492368
        */
        count = (size/2) + 1;
        return count;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/