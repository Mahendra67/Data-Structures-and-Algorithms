#include<iostream>
#include<bits/stdc++.h>
//Leetcode 39
/*
Given an array of distinct integers candidates and a target interer 'target', return a list of all unique combinations of candidates
where the chosen numbers sum up to target. 
The same number can be chosen unlimited amounts of time.
*/
using namespace std;

vector<vector<int>> ans;

void combination(vector<int> can, int size, int target, vector<int>& temp, int idx, int curr_sum){
    if(curr_sum > target){
        return;
    }

    //base case
    if(idx == size){
        if(curr_sum == target){
            //add into ans
            ans.push_back(temp);

            //Print temp
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //We can take same element no. of times
    //Take 
    curr_sum += can[idx];
    temp.push_back(can[idx]);
    //Checking at the same index, since we can use same element for unlimited times
    combination(can, size, target, temp, idx, curr_sum);
    curr_sum -= can[idx];
    temp.pop_back();

    //Not take
    combination(can, size, target, temp, idx+1, curr_sum);
    return;
}

using namespace std;

int main(){
    vector<int> candidates = {2,3,5,2,5,1,9};
    int c_size = candidates.size();
    int start_idx = 0;
    int target = 9;
    int curr_sum = 0;
    vector<int> temp;

    combination(candidates, c_size, target, temp, start_idx, curr_sum);
    return 0;
}