#include<iostream>
#include<bits/stdc++.h>
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
using namespace std;

int maxProfit1(vector<int>& prices) {
    int max_pro = 0;
    for(int i =0; i<prices.size()-1;i++){
        int buy = prices[i];
        for(int j=i+1 ; j<prices.size();j++){
            if(prices[j]>prices[i] && prices[j]-prices[i]>max_pro){
                max_pro = prices[j] - prices[i];
            }
        }
    }
    return max_pro;
}

int maxProfit(vector<int>& prices) {
    int MaxProfitSoFar = 0;
    //Initialising minimum price with int max so that first element will be smaller
    int minimum_price = INT_MAX;
    
    for(int i =0;i<prices.size()-1;i++){
        if(prices[i]<minimum_price){
            minimum_price = prices[i];
        }
        
        int profit = prices[i+1] - minimum_price;

        if(profit > MaxProfitSoFar){
            MaxProfitSoFar = profit;
        }
    }
    return MaxProfitSoFar;
}

int main(){
    vector<int> nums = {7,1,4,6,5,3};


    //Approach 1
    //Brute force
    cout<<maxProfit1(nums);

    cout<<endl;

    //Approach 2
    //Linear traversal
    //Keep track of max_profit_so_far
    //And keep track of minimum price (can initialize it to INT_MAX or first element)
    //If prices[i+1] - minimum_price > max_profit_so_far, update it.
    cout<<maxProfit(nums);

    return 0;
}