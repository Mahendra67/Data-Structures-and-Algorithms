#include<iostream>
#include<bits/stdc++.h>
//Count Primes Leetcode 204

/*
Given an integer n, return the number of prime numbers that are strictly less than n.
*/

using namespace std;

//Brute Force : For every number, check if it is prime or not

/*-----------------------------------------------------------------------------------------------------------*/

//Sieve of Eratosthenes approach
//O(Nlog(logN))
/*
Make a boolean array of size n(since we dont need to check for n -> check for strictly less than n). Assume every number to be prime initially (mark as true -> default)
Now, run a loop from 0 to root(n), and mark all the multiples of currentNo. as false.
NOTE : Don't mark the currentNo. as false.
Only check for multiples if the currentNo. is currently prime (not proved otherwise yet).
Then simply count the no. which remain prime (true) after the loop ends.

Why 0 to root(n) and not 0 to n :
After root(n), the multiples repeat itself. Hence, no need to check after root(n).
*/
class Solution {
public:
    int countPrimes(int n) {
        //Edge cases:
        if(n == 0 || n == 1) return 0;
        
        vector<bool> isPrime(n, true);
        
        //We know that 0 and 1 are not prime numbers
        isPrime[0] = false;
        isPrime[1] = false;
        
        int count = 0;
        
        for(int num=2; num<sqrt(n); num++){
            //Only check for multiples if currentNo. is currently prime
            if(isPrime[num] == true){
                //Check for multiples starting from 2 (number*2) -> 
                //dont change the isPrime[currentNo]
                for(int i=2; num*i<n; i++){
                    isPrime[num*i] = false;
                }
            }
        }
        
        //Now, count the number of primes
        for(int i=0; i<n; i++){
            if(isPrime[i] == true){
                count++;
            }
        }
        
        return count;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/