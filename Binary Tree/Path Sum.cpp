#include<iostream>
#include<bits/stdc++.h>
//Path Sum Leetcode 112

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/


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
    bool pathSum(TreeNode* node, int target){
        //Base case
        
        if(!node){
            return false;
        }
        
        //Make sure base case ends on leaf node
        if(target - node -> val == 0 && !node->left && !node->right){
            return true;
        }
        
        //Work
        bool left = pathSum(node->left, target - node->val);
        
        bool right = pathSum(node->right, target - node->val);
        
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/