#include<iostream>
#include<bits/stdc++.h>
//374 LeetCode
/*
Guess Number Higher or Lower

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
*/
using namespace std;

//Approach 1
 
 //Forward declaration of guess API.
/*@param  num   your guess
@return 	     -1 if num is higher than the picked number
                1 if num is lower than the picked number
            otherwise return 0
*/
int guess(int num);


class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low<=high){

            int mid = ((high-low)/2)+low;
            
            if(!guess(mid)){
                return mid;
            }else if(guess(mid)==1){
                //guess<pick
                low = ++mid;
            }else if(guess(mid)==-1){
                //guess>pick
                high = --mid;
            }
        }
        return 0;
    }
};

int main(){
    
    //Approach 1: Binary Search
    /*
        Do not use (high+low)/2, since it is given that n can be 
        2^31 -1 (int_max).
        If we add high+low, then there are chances of overflow, hence altering
        the original number.
        (high+low)/2 can be written as ((high-low+low)+low)/2.
        Further, simplifying : (high-low)/2 +low;
    */

    return 0;
}