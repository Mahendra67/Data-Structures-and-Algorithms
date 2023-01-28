#include<iostream>
#include<bits/stdc++.h>
//Climbing staris Leetcode 70
/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
using namespace std;

/*
1D Dynamic Programming:
First of all, how do you recognize it is a dp problem?
Hints: 
1. If question starts like - count no. of ways.
2. Or, if the question starts like - there are multiple ways of doing something, give which gives the maximum or minimum output.
3. Concept of try all possible ways -> Then we will use Recursion

Recursion can be used to try all possible ways.
*/

/*
Shortcut for Dynamic Programming questions
1. Try to represent the problem in terms of index.
2. Do all the possible stuff on that index according to the problem statement.
3. For:
    i. COUNT ALL WAYS : Sum of all stuffs
    ii. FIND MIN      : Minimum of all stuffs.
    iii. FIND MAX     : Maximum of all stuffs.
*/

/*----------------------------------------------------------------------------------------------------------------------*/

//Recursion
/*
Assuming the recursive function returns no. of ways
*/
class Solution {
public:
    int climbStairs(int n) {
        //Base cases
        if(n == 0){
            //Only 1 way as it reached the end
            return 1;
        }else if(n == 1){
            return 1;
        }
        
        //Do all possible stuff
        //If you jump 1 back
        int left = climbStairs(n-1);
        
        //If you jump 2 back
        int right = climbStairs(n-2);
        
        return left + right;
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

//Memoization
//Similar to Fibonnaci
class Solution {
public:
    int waysNo(int n, vector<int>& dp){
        if(n == 0) return 1;
        else if(n == 1) return 1;
        
        //Check if the subproblem has already been solved
        if(dp[n] != -1){
            return dp[n];
        }
        
        //All possible ways
        int l = waysNo(n-1, dp);
        int r = waysNo(n-2, dp);
        
        return dp[n] = l + r;
    }
    
    int climbStairs(int n) {
        //Max no. of subproblems = n+1 
        /*f(n), f(n-1), f(n-2), f(n-3), ..........f(0)*/
        vector<int> dp(n+1, -1);
        
        return waysNo(n, dp);
    }
};

/*----------------------------------------------------------------------------------------------------------------------*/

//Tabulation
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        //Base cases
        dp[0] = 1;
        dp[1] = 1;
        
        //In recursive method, recursion is called only for n>=2
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};

/*---------------------------------------------------------------------------------------------------------------------*/

//Tabulation : Space Optimized
class Solution {
public:
    int climbStairs(int n) {
        //Base cases
        // dp[0] = 1;
        int prev2 = 1;
        // dp[1] = 1;
        int prev = 1;
        
        
        //In recursive method, recursion is called only for n>=2
        for(int i=2; i<=n; i++){
            int curr = prev + prev2;
            
            //Update variables
            prev2 = prev;
            prev = curr;
        }
        
        //We can also return curr(as it has same value), but we need to handle edge cases:
        //If n<2 -> curr variable will not be formed -> gives error
        return prev;
    }
};

/*---------------------------------------------------------------------------------------------------------------------*/