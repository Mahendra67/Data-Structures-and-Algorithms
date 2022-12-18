#include<iostream>
#include<bits/stdc++.h>
//Combination sum 2 Leetcode
/*
Same as combination sum 1 but an element can atmost be used 1 times.
Also, note that the solution must not contain duplicates subsequences.
*/
using namespace std;

//Approach1 : BRUTE FORCE
//Since, the answer needed is in sorted order, first sort the given vector
//Do the combination sum approach normally, but instead of storing vector of vector for subsequences you need to store 
//set of vector, so that duplicates subsequences doesn't gets added.
class Solution {
public:
    //BRUTE FORCE METHOD
    void cs(int idx, vector<int> &temp, set<vector<int>>& ans, int target, int size, vector<int> can, int sum){
        if(idx == size){
            if(target == sum){
                ans.insert(temp);
            }
            return;
        }
        
        //take
        temp.push_back(can[idx]);
        cs(idx+1, temp, ans, target, size, can, sum+can[idx]);
        
        //not take
        temp.pop_back();
        cs(idx+1, temp, ans, target, size, can, sum);
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        //Since, we do not want duplicate subsequences, we will use a set to store subsequences.
        set<vector<int>> ans;
        vector<int> temp;
        int start_idx = 0;
        int size = candidates.size();
        int sum = 0;
        
        cs(start_idx, temp, ans, target, size, candidates, sum);
        
        //Now, convert from set of vector to vector of vector.
        vector<vector<int>> v(ans.begin(), ans.end());
        
        return v;
    }
};

//Approach 2: By not taking duplicates values while forming the subsequence  : STRIVER METHOD
class Solution {
public:
    //BRUTE FORCE METHOD
    void cs(int idx, vector<int> &temp, vector<vector<int>>& ans, int target, int size, vector<int> can){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < size; i++){
            if(can[i] > target) break;
            //Why i>idx ??
            if(i>idx && can[i] == can[i-1]){
                continue;
                //Skip if duplicate values
            }
            
            temp.push_back(can[i]);
            cs(i+1, temp, ans, target-can[i], size, can);
            
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int start_idx = 0;
        int size = candidates.size();
        
        cs(start_idx, temp, ans, target, size, candidates);

        return ans;
    }
};

int main(){
    
    return 0;
}