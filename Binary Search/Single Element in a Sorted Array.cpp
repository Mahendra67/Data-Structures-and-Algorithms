#include<iostream>
#include<bits/stdc++.h>
//Single element in a sorted array Leetcode 540

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :     O(n)
SC    :     O(1)
*/

/* O(n)
Approach 1: Take XOR of all elements.
A^A = 0
A^0 = A
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(auto& it:nums){
            ans = ans^it;
        }
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :     O(log n)
SC    :     O(1

)
*/

/*
For mid number: 3 cases are possible
1.  Either its duplicate is on the left side
2.  Or its duplicate is on the right side
3.  It is the single element (no duplicate of mid no. found at either side)


Now, since it is given that every elements appear exactly twice, except for one element, it is sure that the no. of elements in given array will always be odd.

e.g. The dotted lines represent spaces(we dont know where single element is)
_ _ _ _ 4 _ _ _ _ 

*********************************************************************************
IF THE DIVIDED SUBARRAYS LENGTH ARE OF EVEN NO. (divided by mid element)

Lets say, when we find mid element, the duplicate is on the right side.
_ _ _ _ 4 4 _ _ _

Since the array is sorted and duplicate of mid element is found -> numbers are segregated.
(Left of mid will be nos. less than 4 and right of mid's duplicate will have nos. greater than 4). 

This means on the left side -> even number of spaces (as duplicate was found on right side). (4 spaces left) -> Asssuming the single element takes one space, spaces remaining of the 'left' side -> 3 (odd). No way to fill it fully with pairs(element, element's duplicate) as one space will always be empty. Hence, the single element can never be on the left side.

On the right side, since mid's duplicate was taking 1 space -> remaining spaces are 3(which is odd). Assuming one space is taken by the single element, spaces remaining (2) -> even.
It can be fully filled with pairs of (element, duplicate element).

Hence, if we find mid's duplicate on right side -> single element would also be found on the right side. Same with left side. (If the divided subarrays are of EVEN length)

************************************************************************************
IF THE DIVIDED SUBARRAYS LENGTH ARE OF ODD NO.

Lets say:
_ _ _ 4 _ _ _ 

If we find mid's duplicate on left side
_ _ 4 4 _ _ _

The remaining spaces to fill are even -> can be filled by pair of (element, duplicate).
While the right side have odd spaces to fill -> no way to completely fill the right side with pairs. Hence single element is on the right side. Same with right side.
(If the divided subarrays are of ODD length)

************************************************************************************

If we find no duplicate for mid element -> that is the single element.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;
        
        int SingleElement;
        
        while(low <= high){
            //Fancy way of writing (low+high)/2
            int mid = ((high-low)>>1) + low;
            
            //Check if divided subarrays are odd or even
            int isEven = ((high-mid)%2 == 0)? 1 : 0;
            
            //If we find duplicate on left side
            if(mid > 0 && nums[mid-1] == nums[mid]){
                if(isEven == 1){
                    high = mid-2;
                }else{
                    low = mid + 1;
                }
                
            }else if(mid < n-1 && nums[mid] == nums[mid+1]){
                //found duplicate on right side
                if(isEven == 1){
                    low = mid+2;
                }else{
                    high = mid-1;
                }
                
            }else{
                //Found no duplicates -> single element
                SingleElement = nums[mid];
                break;
            }
            
        }
        
        return SingleElement;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/