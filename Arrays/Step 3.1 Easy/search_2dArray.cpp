#include<iostream>
#include<vector>
//Search for an element in sorted 2d matrix
using namespace std;

int main(){
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    

    //Approach 1
    //Brute force using 2 nested loop


    //Approach 2
    //from the start, check the last element of the row
    //Compare it with target, if it is more than target, use binary search in current row
    

    //Approach 3 
    //Using a pointer that starts at pointing towards nums[0][col-1]
    //If more than target, go left(j--)
    //If less than target, go under (i++)
    return 0;
}