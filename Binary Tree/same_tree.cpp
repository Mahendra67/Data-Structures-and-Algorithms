#include<iostream>
#include<bits/stdc++.h>
//100 Leetcode
/*
Given root nodes of two binary tree, check if they both are identical tree.
*/
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 1: Recursive
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        //Comes here if atleast 1 of them is not NULL
        if(!p || !q) return false;
        
        //default ans to false
        bool ans = false;
        if(p->val == q->val){
            ans = true;
        }
        
        //left call
        bool left = isSameTree(p->left, q->left);
        
        //right tree
        bool right = isSameTree(p->right, q->right);
        
        //Only return true if the whole subtree is equal(along with its value)
        return ans&&left&&right;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1: Recursive
    /*
    Check if both root nodes are NULL, if yes then return true.
    It will come under here if atleast one of them is not NULL.
    Check if any of them are NULL, if yes, then return false(since atleast 1 of them is not NULL).

    Return true if both nodes values are same and its left subtree and right subtree are same.
    */
    return 0;
}