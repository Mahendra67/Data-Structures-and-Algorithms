#include<iostream>
#include<bits/stdc++.h>
//Fibonacci number using dynamic programming

//If subproblems are already solved, 
/*
In memoziation, we tend to store the values of subproblems in some map/table
*/
using namespace std;

/*
3 steps:
1. Declare a dp array of suitable size to store values of solved subproblems.
2. Store the value of solved subproblems into that dp array.
3. Before calling further recursive call, check if it has been already solved
*/

/*
TC - O(n)
O(n) since we are not calulating subproblems again.
e.g. For f(4), it will only calcualte f(4), f(3), f(2), f(1), f(0) one time, hence O(n) times
SC - O(n) + O(n) 
O(n) for array maintained, and O(n) for the recursion stack space used
*/
int fibonacci(int n,vector<int>& dp){
    if(n<=1){
        return n;
    }

    //to convert this problem from recursion to dynamic programming, check if the subproblem has been already solved
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}




/*
Now, how do you convert from recursion to tabulation format

Tabulation: Bottom-up approach
Go from base case to the required case

Steps:
1. Write the base cases
2. Check the starting number from where the answer will proceed onwards.
e.g. In case of fibonacci numbers:
    Base cases are f(0) and f(1).
    And for everything else, it will go from 2->n.
*/



int main(){
    int n = 5;
    //Declare a dp array to store values for solved subproblems with initialized it to -1
    //In this case:
    /*
    There can be maximum of n+1 different subproblems.
    e.g. 
    For fibonacci(4) 
    there will be 4, 3, 2, 1, 0 -> 5 subproblems
    */
    //If you solve a subproblem, store that value in that array index.
    //If value of an index is other than -1, use that value instead of solving that subproblem again
    vector<int> dp(n+1,-1); 

    cout<<"From memoization :"<<fibonacci(n, dp)<<endl;

    //For tabulation
    /*
    TC -  O(n)
    SC -  O(n)
    O(n) for the vector maintained for storing values of subproblems
    Reduced the space complexity since we are not using recursion stack
    */
    vector<int> dp2(n+1,-1);
    //Base cases
    dp2[0] = 0;
    dp2[1] = 1;

    for(int i=2; i<=n; i++){
        dp2[i] = dp2[i-1] + dp2[i-2];
    }

    cout<<"From tabulation : "<<dp[n];


    //You can further optimise the tabulation space complexity 
    int prev2 = 0;
    int prev = 1;
    int curr;

    for(int i=2; i<=n; i++){
        curr = prev + prev2;

        //Now update prev2 and prev
        prev2 = prev;
        prev = curr;
    }

    cout<<endl<<"From tabulation but space optimised: "<<prev;


    return 0;
}