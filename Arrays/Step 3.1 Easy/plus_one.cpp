#include<iostream>
#include<bits/stdc++.h>
//66 LeetCode
/*
ou are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = digits.rbegin();
        
        while(*(it)==9){
            *(it) = 0;
            /*Since we used rbegin as iterator, in order to traverse backwards
            we need to increment it by 1*/
            ++it;
            if(it==digits.rend()){
                //increase the vector capacity by 1
                digits.emplace_back(0);

                //Since we increased size of vector, we need to recalculate iterator
                /*Since, increasing vector size -> vector gets copied at other address with more capacity*/
                auto it = digits.begin();
                *(it) = 1;
                return digits;
            }
        }
        *(it) = *(it)+1;
        
        return digits;
    }
};

int main(){
    

    //Approach 1 : Using iterators
    /*
    Checking from back of the vector, if it is not 9, then simply incrementing it by 1 and returning the vector.
    If it is 9, update the element at that index to zero. Keep doing this until you find element other than 9.
    If the iterator reaches the rend() iterator, then increase the vector space by 1. 

    Increasing the vector size works in such a way that all elements of old vector gets copied to new address with more capacity.
    Hence, we need to update the iterator.
    */
    return 0;
}