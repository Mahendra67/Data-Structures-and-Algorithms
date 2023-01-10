#include<iostream>
#include<bits/stdc++.h>
//Geek Jump GFG
/*
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. 
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump 
is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used 
by the Geek to jump from stair 0 to stair N-1.
*/
using namespace std;

/*------------------------------------------------------------------------------------------------------------------*/

//BASIC RECURSION APPROACH
class Solution {
    /*
    1 based indexing -> change to 0 based 
    Now, we have to find min energy to reach (n-1)th node from 0th node (or vice versa). -> f(n-1)
    
    f(0) means min energy to reach 0th node from 0th node = 0 -> this becomes base case
    */
  public:
    int minEnergy(int n, vector<int>& height){
        //Base case
        if(n == 0) return 0;
        
        //Geek can jump 1 or 2 steps at a time.
        /*
        For 1 step:
        Cost to reach (n-1)th node from nth node
        */
        int cost1 = std::abs(height[n] - height[n-1]);
        //Have faith in recursion, that it will tell the cost to reach 0th node from (n-1)th node
        //Total cost = cost from 0 to n-1 + cost to n-1 to n
        int consider1 = minEnergy(n-1, height) + cost1;
        
        /*
        For 2 steps:
        Cost to reach (n-2)th node from nth node
        */
        //If n becomes less than 1, then n-2 will give negative value -> Not a valid step
        int consider2 = INT_MAX;
        if(n > 1){
            int cost2 = std::abs(height[n] - height[n-2]);
            consider2 = minEnergy(n-2, height) + cost2;
        }
        
        return min(consider1 , consider2);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        
        return minEnergy(n-1, height);
    }
};

/*------------------------------------------------------------------------------------------------------------------*/

class Solution {
  /*
  Memoization Approach :
  */
  public:
    int minEnergy(int n, vector<int>& height, vector<int>& dp){
        //Base case
        if(n == 0) return 0;
        
        /*----------------------------------------------------------*/
        //Check if the given subproblem is already solved
        if(dp[n] != -1){
            return dp[n];
        }
        /*----------------------------------------------------------*/
        
        //Geek can jump 1 or 2 steps at a time.
        /*
        For 1 step:
        Cost to reach (n-1)th node from nth node
        */
        int cost1 = std::abs(height[n] - height[n-1]);
        //Have faith in recursion, that it will tell the cost to reach 0th node from (n-1)th node
        //Total cost = cost from 0 to n-1 + cost to n-1 to n
        int consider1 = minEnergy(n-1, height, dp) + cost1;
        
        /*
        For 2 steps:
        Cost to reach (n-2)th node from nth node
        */
        //If n becomes less than 1, then n-2 will give negative value -> Not a valid step
        int consider2 = INT_MAX;
        if(n > 1){
            int cost2 = std::abs(height[n] - height[n-2]);
            consider2 = minEnergy(n-2, height, dp) + cost2;
        }
        
        return dp[n] = min(consider1 , consider2);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        
        //For memoization
        vector<int> dp(n,-1);
        
        return minEnergy(n-1, height, dp);
    }
};

/*------------------------------------------------------------------------------------------------------------------*/

class Solution {
    //Tabulation appraoch
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, 0);
        
        //Base
        //min Cost to reach 0th node from 0 is 0
        dp[0] = 0;
        
        //min Cost to reach 1th node from 0 has only 1 way
        dp[1] = std::abs(height[0] - height[1]);
        
        //for n>2, apply loop
        for(int i=2; i<n; i++){
            //If we jump 1 step
            // cost = cost to jump 1 step back + min cost from (curr-1)th node to 0th node
            int cost1 = std::abs(height[i] - height[i-1]);
            int l = cost1 + dp[i-1];
            
            //If we jump 2 step
            // cost = cost to jump 2 step back + min cost from (curr-2)th node to 0th node
            int cost2 = std::abs(height[i] - height[i-2]);
            int r = cost2 + dp[i-2];
            
            dp[i] = min(l, r);
        }
        
        //Since we changed 1 based indexing to 0-based indexing
        return dp[n-1];
    }
};

/*------------------------------------------------------------------------------------------------------------------*/

/*
If there exists something as dp[i-1] and dp[i-2] -> space optimization exists
*/
class Solution {
    //Tabulation appraoch : Space Optimized
  public:
    int minimumEnergy(vector<int>& height, int n) {
        //Base
        //min Cost to reach 0th node from 0 is 0
        // dp[0] = 0;
        int prev2 = 0;
        
        //min Cost to reach 1th node from 0 has only 1 way
        // dp[1] = abs(height[0] - height[1]);
        int prev = std::abs(height[0] - height[1]);
        
        //for n>2, apply loop
        for(int i=2; i<n; i++){
            //If we jump 1 step
            // cost = cost to jump 1 step back + min cost from (curr-1)th node to 0th node
            int cost1 = std::abs(height[i] - height[i-1]);
            int l = cost1 + prev;
            
            //If we jump 2 step
            // cost = cost to jump 2 step back + min cost from (curr-2)th node to 0th node
            int cost2 = std::abs(height[i] - height[i-2]);
            int r = cost2 + prev2;
            
            int curr = min(l, r);
            
            //Update prev variables
            prev2 = prev;
            prev = curr;
        }
        
        
        return prev;
    }
};

/*------------------------------------------------------------------------------------------------------------------*/