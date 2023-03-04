#include<iostream>
#include<bits/stdc++.h>
//Fractional Knapsack GFG

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/


struct Item{
    int value;
    int weight;
};


/*
Inutition:
For each fraction of items we are selecting, make sure that you get the best possible value-to-weight ratio.
Start by selecting those items which have higher value/weight ratio.

Approach:
Sort the array by value/weight ratio.
Now, start from 1st element -> select as much fractional items as you can from that element.
Do the same for others until you reach your max capacity.
*/

/*
struct Item{
    int value;
    int weight;
};
*/

/*
For comparators in c++: It returns bool values -> false means swap the arguments, true means dont swap.

//argument a comes before than argument b in original data structure
//if it returns false, argument a gets swapped with b -> now 'b' comes before 'a'

bool comp(int a, int b){
    if(a > b) return false;
    return true;
} -> sorts in ascending order

sort(m.begin(), m.end(), comp);

SHORTCUT FOR DEFINING COMPARATORS : Return the order which you want.
For eg. if you want ascending order : return a < b;

bool cmp(int a, int b){
    return a < b; 
}

If a < b in original D.S., then it will return true -> dont swap.
If a > b in original D.S., then (a < b) will return false -> swaps the values
*/

//Custom comparator
    bool custom_cmp(Item a, Item b){
        double ratio1 = (double)a.value/a.weight;
        double ratio2 = (double)b.value/b.weight;
        
        return ratio1 > ratio2;
    }

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //First sort it according to value/weight ratio
        sort(arr, arr+n, custom_cmp);
        
        double ans=0;
        
        //Now pick max fraction's of an item that you can pick
        for(int i=0; i<n; i++){
            //In case: W becomes zero -> break out
            if(W == 0) break;
            
            //If you can fit the whole item in the bag
            if(arr[i].weight <= W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                //If you can't fit the whole item in the bag -> take as much as possible
                
                //We need the fractions that weigh = remaining W.
                //Find value of 1 unit, multiply by W.
                double UnitValue = (double)arr[i].value/arr[i].weight;
                
                double Wvalue = (UnitValue * W);
                
                //Add it into ans
                ans += Wvalue;
                break;
            }
        }
        
        return ans;
    }
        
};




/*-----------------------------------------------------------------------------------------------------------*/