#include<iostream>
#include<bits/stdc++.h>
//Power of two 231 Leetcode
/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long int n1 = n;
        if(n1==0) return false;
        
        long int n2 = n1-1;
        
        if((n1 & n2) == 0){
            return true;
        }else return false;
    }
};

/*
If a number is a power of two, that means its binary representation would only have one trailing '1', and the 
rest would be zero. If we take number 1 less than given numeber, then it's binary representation would be the opposite 
of the above number. (If the original number is power of 2). Do bitwise & between those numbers, if zero -> true, else false.

BINARY EXAMPLE :

        8   4   2   1
For 8:  1   0   0   0
For 7:  0   1   1   1

& _____________________
        0   0   0   0

*/

int main(){
    
    return 0;
}