#include<iostream>
#include<bits/stdc++.h>
//236 Leetcode
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
*/
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Approach 1: Recursive , postorder traversal
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        //Using postorder traversal
        //Base : If node becomes null OR
        //If any one node becomes equal to given address, return the node.
        if(!root ||(root==p || root==q)) return root; 
        
        //Left
        TreeNode* add1 = lca(root->left,p,q);        
        
        //Right
        TreeNode* add2 = lca(root->right,p,q); 
        
        
        //If both of them return something other than null for first time, it means current 
        //node is lowest common ancestor
        if(add1 && add2) return root;
    
        
        //If the returned value is something other than nullptr, return that same address
        //(1 returns null and other return some address)
        if(add1){
            return add1;
        }else if(add2){
            return add2;
        }
        
        //If add1 and add2 both gives nullptr
        return nullptr;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};

int main(){
    

    //Approach 1: Using postorder traversal using recursion
    
    //If you find the given address, return the address, 
    //keep returning this address until both sides of node of subtree returns other than null.

    //If you didnt, return NULL.


    /*
    Give a left call and right call.

    If you find NULL or address of nodes equal to given any of the 2 address, return root.
    Since, returning NULL root would also given NULL.

    Check if left returned address is not NULL and right returned address is also not NULL.
    If yes, then return the current node address, as it is the lowest common ancestor.

    If a call returns NULL, but other call returns address, return that address.
    IF both calls returns NULL, return null.
    */
    return 0;
}