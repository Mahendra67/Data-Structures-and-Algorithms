#include<iostream>
#include<bits/stdc++.h>
//Capacity to Ship Packages withing D Days Leetcode 1011

/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages 
on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight 
capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being 
shipped within days days.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

/*
Approach:
We know that the minimum capacity of the ship should be the max weight of one package.
(Even if we take less ships/days than no. of packages, the packages will be grouped) -> making the weight of each grouped package larger. Hence, min capacity -> max of weight[i] of pacakges.

//Assuming 6 is the max weight[i]
Now, we know that least weight/capacity lies in range [6,........]. (we know the lower bound)

Check if there exists an upper bound. (If yes, then usually we can apply Binary search)

The max weight/capacity of a ship can be the total sum of the weights of the package.
(Assuming all packages are shipped at 1st day).

Now, we know the range of answer(capacity) -> [max(weight[i]), sumOfAllPackages]

Brute force: Start from max(weight[i]) -> one by one, iteratively, check if all the packages can be shipped in given ships/days for the given capacity.

Binary Search: Apply binary search:
If at mid value of capacity's range, we are able to ship all packages in given days/ships -> that means for all the values greater than mid(capacity) will also be able to ship the packages in the given days.
e.g.[-----4 5 6 7] -> If it is possible for capacity=4, then the packages can also be shipped
in greater capacity ships.
But we need the MINIMUM
capacity for the ship. Hence, we look in the left half of the range.

If at mid value of capacity's range, we are not able to ship all packages -> means the given capacity is not enough. Also, for lower capacity ship(than the current one) -> it will also be not possible. Hence, look at right half of the range.
*/
class Solution {
public:
    bool isPossible(int capacity, vector<int>& weights, int days){
        int temp = capacity;
        int i = 0;
        int n = weights.size();
        
        //How many ships or days used
        int ships = 1;
        
        while(i<n){
            temp -= weights[i];
            
            if(temp < 0){
                temp = capacity;
                ships++;
                
                //And put the current package in new ship
                temp -= weights[i];
            }
            
            i++;
        }
        
        // cout<<capacity<<" "<<ships<<" "<<temp<<endl;
        //If some capacity is still left or is zero, and if days == ships , then is possible
        //It is also possible if it takes less no. of days/ships then given days
        if(temp >= 0 && ships <= days){
            return true;
        }
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxiWeight = -1e8;
        for(auto it: weights){
            maxiWeight = max(maxiWeight, it);
        }
        
        //Now we have the lower bound
        int lowerBound = maxiWeight;
        
        //Find the upper bound (sum of all weights)
        //This could have been done in upper loop, but for understanding purposes, new loop is used
        int sum = 0;
        for(auto &it: weights){
            sum += it;
        }
        
        int upperBound = sum;
        
        //We need to search for minCapacity that the ship needs in the range given
        int low = lowerBound;
        int high = upperBound;
        
        
        int MinCap = lowerBound;
        
        while(low <= high){
            //Check if current capacity can take all the packages in given days/ships
            //mid == current capacity
            int mid = ((high-low)>>1)+low;
            
            if(isPossible(mid, weights, days)){
                //Check if any lower Capacity ship can do the job
                high = mid-1;
                
                //Update MinCap found so far
                MinCap = mid;
            }else{
                low = mid+1;
            }
        }
        
        return MinCap;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/