#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Linear Traversal
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                pos = i+1;
            }
            if(nums[i]==target) return i;
        }
        
        //Not found
        return pos;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        
        while(l<=h){
            int mid = l + (h-l)/2 ;
            //To avoid overflow
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
        
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){

//   Approach 1: 
    /*
    Linearly traverse through the array, keep a variable pos(stores index) which only updates if 
    element at that is smaller than target.
    If you find the target, return its index, else, return the pos+1 (since, the element pos is pointing at is
    smaller than target, hence we need to insert target in pos+1).
    */



//    Approach 2: Binary Search
   /*
    Why did we return low, instead of mid?
    
    //In last comparison
    
    Case I : Target is greater than mid element
    [2] -> Assume this is array and target is 4
    l = 0, h = 0;
    mid = 0 
    Since, target is more than arr[mid] -> left pointer shifts to right of 2
    [ 2 ]
        |     |
        high   low
        Breaks condition, now, low is pointing to the position where we want to insert 4
        
        
        Case I : Target is less than mid element
    [2] -> Assume this is array and target is 1
    l = 0, h = 0;
    mid = 0 
    Since, target is less than arr[mid] -> right pointer shifts to left of 2
            [ 2 ]
        |     |
        high   low
        Breaks condition, now, low is pointing to the position where we want to insert 1
        
    */
    return 0;
}