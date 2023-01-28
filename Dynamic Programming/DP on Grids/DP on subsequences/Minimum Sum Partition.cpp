#include<iostream>
#include<bits/stdc++.h>
//Minimum Sum Partition GFG
//DOESNT WORK FOR NEGATIVE ELEMENTS

/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 
and S2 such that the absolute difference between their sums is minimum and find the minimum difference
*/

using namespace std;

/*
If you are using recursion/memoization instead of tabulation, the last row may have some unvisited grid cells.
Recursion will fill only specific cells. For the last row in dp grid, only the last cell will be filled.
While in tabulation, every cell will get visited atleast once. (tabulation is preferred)
*/

/*-----------------------------------------------------------------------------------------------------------*/

/*
DOESNT WORK FOR NEGATIVE ELEMENTS
Approach:
A array can be divided into 2 subsets as:
1 subset can have maximum all the elements of original array, and it can have minimum of 0 elements.

Total sum of the array can be calculated. 
If we know the sum of 1st subset, its complementary subset can be calculated using 
        Subset2Sum = totalSum - Subset1Sum;
        
Subset1 range - (0, totalSum)
Subset1 sum lies between the above range, but it may be possible that no combination of the elements of original 
array can form all the numbers in Subset1 sum range.
e.g.    [3,4,5,10]
Total sum = 22
Subset1 sum range (0, 22)
No combination of given elements can form subset1 sum as 11.

Hence, in Subset1 range, check which values are possible to form.
Using that, return the min difference.

*/

/*
If we find whether totalSum is possible or not using dp grid, then we can observe that the last row
grid[maxRow-1][target range lies from (0 to totalSum)] -> gives whether it is possible to form subset with
that target value.
*/

class Solution{
  public:
    int minDifference(int arr[], int n)  { 
	    //Find the total sum of original array
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	    }
	   
	    
	    //idx can range from 0 to arr.size()-1
	    //target can range from 0 to totalSum
	    vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
	    
	    /*------------------------------TABULATION---------------------------------------------------*/
	    
	    //Edge cases
	    //If target is zero -> true
	    for(int row=0; row<n; row++){
	        dp[row][0] = true;
	    }
	    //If only 1 element, and index is zero: true -> if element == target
	    dp[0][arr[0]] = true;
	    
	    //row siginifies individual elements index
	    for(int row=1; row<n; row++){
	        //column1 is already filled, hence started from target=1th col
	        for(int target=1; target<=sum; target++){
	            bool notTake = dp[row-1][target];
	            
	            bool take = false;
	            if(target >= arr[row]){
	                take = dp[row-1][target - arr[row]];
	            }
	            
	            dp[row][target] = take || notTake;
	        }
	    }
	    
	    /*-------------------------------------------------------------------------------------------*/
	    //Now, we have found which sum are possible for subset1 as the last row of dp array is filled
	    //Using this we can find the minimum diff
	    /*
	    sub1 can range from 0 to totalSum.
	    But after (totalSum/2), the values will repeat.
	    The values that were for S1 in first half will become values for S2 in second half. (and viceversa)
	    */
	    
	    
	    
	    int minimum = 1e9;
	    for(int sub1=0; sub1 <= (sum/2); sub1++){
	        //last row of dp tells us if subset sum is possible or not
	        if(dp[n-1][sub1] == 1){
	            int sub2 = sum - sub1;
	            int diff = std::abs(sub1 - sub2);
	            minimum = min(minimum, diff);
	        }
	    }
	    
	    return minimum;
	} 
};

/*-----------------------------------------------------------------------------------------------------------*/