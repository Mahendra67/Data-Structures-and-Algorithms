#include<iostream>
#include<bits/stdc++.h>
//Path Sum II Leetcode 113

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node 
values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

//Using ref variable only
struct TreeNode {     
    int val;     
    TreeNode *left;     
    TreeNode *right;     
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void path(TreeNode* node, int target, vector<vector<int>>& ans, vector<int>& temp){
        //Base cases
        if(!node){
            return;
        }
        
        temp.push_back(node->val);
        
        
        //Target becomes equal to leaf node value
        if(target == node -> val && !node->left && !node->right){
            //Found a path            
            ans.push_back(temp);
            
            //Since temp is passed by ref and the function return after this line
            //the last element doesn't gets removed while backtracking
            //we need to explicitly remove it
            temp.pop_back();
            return;
        }
        
        //work       
        path(node->left, target - node->val, ans, temp);
        
        path(node->right, target - node->val, ans, temp);
        temp.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        path(root, targetSum, ans, temp);
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/