#include<iostream>
#include<bits/stdc++.h>
//Min Cost climbing stairs Leetcode 746
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------*/

//NORMAL RECURSION
class Solution {
public:
    int minCost(int n, vector<int>& cost){
        //Base case:
        //Either it reaches zero, or it reaches 1 (from nth node)
        if(n == 0 || n == 1){
            return cost[n];
        }
        
        //If we consider 1 step back
        int os = minCost(n-1, cost) + cost[n];
            
        //If we consider 2 step back
        int ss = minCost(n-2, cost) + cost[n];
        
        return min(os, ss);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //Since the starting index can be 1 or 0, we need to find all the ways and return min
        //If 0 is starting index
        int ls = minCost(n-1, cost);
        
        //If 1 is starting index
        int rs = minCost(n-2, cost);
        
        return min(ls, rs);
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

//Memoization
class Solution {
public:
    int minCost(int n, vector<int>& cost, vector<int>& dp){
        //Base case:
        //Either it reaches zero, or it reaches 1 (from nth node)
        if(n == 0 || n == 1){
            return cost[n];
        }
        
        //Check if the subproblem has already been solved before
        if(dp[n] != -1){
            return dp[n];
        }
        
        //If we consider 1 step back
        int os = minCost(n-1, cost, dp) + cost[n];
            
        //If we consider 2 step back
        int ss = minCost(n-2, cost, dp) + cost[n];
        
        return dp[n] = min(os, ss);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        //For memoization
        vector<int> dp(n, -1);
        
        //Since the starting index can be 1 or 0, we need to find all the ways and return min
        //If 0 is starting index
        int ls = minCost(n-1, cost, dp);
        
        //If 1 is starting index
        int rs = minCost(n-2, cost, dp);
        
        return min(ls, rs);
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

//Tabulation
class Solution {
public:    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        
        //Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++){
            //Consider 1 step
            int cost1 = dp[i-1] + cost[i];
            
            //Consider 2 step
            int cost2 = dp[i-2] + cost[i];
            
            dp[i] = min(cost1, cost2);
        }
        
        //Index can start from 0 or 1
        //Return the min from those two
        return min(dp[n-1], dp[n-2]);
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

//Tabulation : Space optimized
class Solution {
public:    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        //Base cases
        int prev2 = cost[0];
        int prev = cost[1];
        
        for(int i=2; i<n; i++){
            //Consider 1 step
            int cost1 = prev + cost[i];
            
            //Consider 2 step
            int cost2 = prev2 + cost[i];
            
            int curr = min(cost1, cost2);
            
            //Update 
            prev2 = prev;
            prev = curr;
        }
        
        //Index can start from 0 or 1
        //Return the min from those two
        return min(prev, prev2);
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/