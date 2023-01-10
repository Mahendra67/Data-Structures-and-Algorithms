#include<iostream>
#include<bits/stdc++.h>
//Minimal Cost GFG
/*
There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: 
Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the 
minimum possible total cost incurred before the Geek reaches Stone N.
*/
using namespace std;

/*--------------------------------------------------------------------------------------------------------------*/

//BASIC RECURSION APPROACH : O(k^n)
//SC : O(n) -> stack space
class Solution {
  public:
    int minCost(int n, int k, vector<int>& height){
        //Base case
        if(n == 0) return 0; // already at 0th index
        
        int minEnergy = INT_MAX;
        for(int jumps=1 ; jumps<=k; jumps++){
            //k is no. of steps considered
            
            //Make sure index doesn't becomes negative
            if(n - jumps >= 0){
                int energy = minCost(n-jumps, k, height) + std::abs(height[n] - height[n-jumps]);
            
                //Store min enery
                minEnergy = min(minEnergy, energy);
            }
            
        }
        
        return minEnergy;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        return minCost(n-1, k, height);
    }
};

/*--------------------------------------------------------------------------------------------------------------*/

//Memoization : O(n) * k
//SC : O(n) + O(n) 
class Solution {
  public:
    int minCost(int n, int k, vector<int>& height, vector<int>& dp){
        //Base case
        if(n == 0) return 0; // already at 0th index
        
        //Check if already solved
        if(dp[n] != -1){
            return dp[n];
        }
        
        int minEnergy = INT_MAX;
        for(int jumps=1 ; jumps<=k; jumps++){
            //k is no. of steps considered
            
            //Make sure index doesn't becomes negative
            if(n - jumps >= 0){
                int energy = minCost(n-jumps, k, height, dp) + std::abs(height[n] - height[n-jumps]);
            
                //Store min enery
                minEnergy = min(minEnergy, energy);
            }
            
        }
        
        return dp[n] = minEnergy;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);
        
        return minCost(n-1, k, height, dp);
    }
};

/*--------------------------------------------------------------------------------------------------------------*/

//Tabulation 
//TC : O(n*k)
//SC : O(n)
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, 0);
        
        //Base case
        //To reach node 0 -> dist = 0
        dp[0] = 0;
        
        //Now, i -> node
        for(int i=1; i<n; i++){
            //For each node, we can jump maximum of k nodes
            
            //MinCost to reach i node
            int minCost = INT_MAX;
            for(int jump=1; jump<=k; jump++){
                //check for valid index
                if(i - jump >= 0){
                    int cost = dp[i - jump] + std::abs(height[i] - height[i - jump]);
                
                    minCost = min(minCost, cost);
                }
            }
            
            //Now the minCost to reach node 'i' is stored in minCost
            dp[i] = minCost;
        }
        
        return dp[n-1];
    }
};

/*-----------------------------------------------------------------------------------------------------------*/
//To space optimize it, you can carry a vector/array to store previous k elements. After each node iteration, just remove the first 
//element and push the current node cost to the array.
//It can be max space optimized to O(k)