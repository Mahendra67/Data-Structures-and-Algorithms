#include<iostream>
#include<vector>
#include<unordered_map>
//Find no. of subarrays such that their sum is k\

//For reference of O(n) solution
//https://www.youtube.com/watch?v=20v8zSo2v18
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    //Using prefix sum method
    int arr[nums.size()];
    int sum1 = 0;

    //If array was              [3,4,7 ,2 ,-3,1 ,4 ,2 ]
    //Prefix sum array would be [3,7,14,16,13,14,18,20]
    //                               i|    j| 
    //To get the sum of the observing array,(from i to j) 
    //Sum = (Sum of elements upto jth array of original element) - (Sum of elements upto (i-1)th array of original element)
    //Sum  = prefix[j] - prefix[i-1]
    //To avoid segmentation fault, add if(i==0) then sum  = prefix[j];
    
    for(int i=0;i<nums.size();i++){
        arr[i] = sum1 + nums[i];
        sum1 = arr[i];
    }

    int sum;
    for(int i=0; i<nums.size() ;i++){
        for(int j = i; j<nums.size() ;j++){
            if(i == 0){
                sum = arr[j];
            }else{
                sum = arr[j] - arr[i-1];
            }
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

//Approach O(n)
int subarraySum2(vector<int>& nums, int k) {
    //Using hashmaps
    int count = 0;
    int sum = 0;
    unordered_map<int,int> mpp;
    
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        
        if(sum == k){
            //Means the subarray is starting from 0th index
            count++;
        }
        
        //If find doesnt finds the key-pair it returns end() iterator
        if(mpp.find(sum-k)!=mpp.end()){
            //if(sum-k) exists in prefix sum hashmap, then subarray with sum k exists
            count += mpp[sum-k];
            //Adding frequency of prefix sum to count
        }
        
        //Adding to hashmap
        if(mpp.find(sum)!=mpp.end()){
            //'sum' key already exists, hence increase its frequency
            mpp[sum]++;
        }else{
            //'sum' key doesn't exist, add to hashmap
            mpp[sum] = 1;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {3,4,7,2,-3,1,4,2};
    int k = 7;

    //Approach 1 O(n^3)
    //Using 2 loops to find all the sub arrays and 1 more nested loop to find the sum


    //Approach 2 O(n^2)
    //Using prefix sum approach
    cout<<subarraySum(nums,k);

    cout<<endl;


    //Approach 3 O(n)
    cout<<subarraySum2(nums,k);
    return 0;
}