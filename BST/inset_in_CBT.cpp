#include<iostream>
#include<bits/stdc++.h>
//701 LeetCode : Insert into Binary Search Tree
/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.
You can return any of them.
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



//Approach 1 : Recursive O(n)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //Edge case: If BST is empty
        if(!root){
            TreeNode* n1 = new TreeNode(val);
            return n1;
        }
        
        //Base
        if(root->val < val && !root -> right){
            TreeNode* n1 = new TreeNode(val);
            root -> right = n1;
            return root;
        }else if(root->val > val && !root -> left){
            TreeNode* n2 = new TreeNode(val);
            root -> left = n2;
            return root;
        }
        
        //Since, it is guaranteed that new value doesnt exist in BST
        //We dont need to check for equality
        if(root->val < val){
            insertIntoBST(root->right,val);
        }else if(root->val > val){
            insertIntoBST(root->left,val);
        }
        return root;
    }
};

int main(){
    

    //Approach 1: Recursive 
    /*
    First, check for edge case: If root is NULL, then create a new TreeNode and return its address.
    Else,
        Base: Check if key is less than current node's value and if left child is empty.
            If yes, then create a new TreeNode with the key value, and return root.
            Else if
                Check if key is greater than current node's value and if right child is empty.
                If yes, then create a new TreeNode with the key value, and return root.
            
        IF key is less than current node's value, give a right recursive call.
        If key is greater than current node's value, give a left recursive call.

        Return root of the tree.
    */
    return 0;
}