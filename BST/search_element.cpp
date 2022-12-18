#include<iostream>
#include<bits/stdc++.h>

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
    TreeNode* check(TreeNode* node,int val){
        //Base case
        if(!node) return nullptr;
        
        //work
        if(node->val == val) return node;
        
        //left call
        TreeNode* t1 = check(node->left,val);
        //When t1 has some address other than nullptr, then element is found
        if(t1){
            return t1;
        }
        
        //right call
        TreeNode* t2 = check(node->right,val);
        //When t2 has some address other than nullptr, then element is found
        if(t2){
            return t2;
        }
        
        //If element not found, then return from the subtree and return nullptr
        return nullptr;
        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return check(root,val);
    }
};

// Approach 3 :Recursive
//If the given tree is balanced, then the time complexity would be O(log n)
//If the given tree is not balanced, then the worst case could be if it is built like a chain, hence O(n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //Base case
        if(!root) return NULL;
        
        TreeNode* add1;
        TreeNode* add2;
        
        if(root->val == val){
            return root;
        }else if(val > root->val){
            add1 = searchBST(root->right,val);
        }else if(val < root->val){
            add2 = searchBST(root->left,val);
        }
        
        //If any one of the add1 and add2 is not NUll, return their address
        //If both of them are NULL, return NULL
        if(add1!=NULL){
            return add1;
        }else if(add2!=NULL){
            return add2;
        }else{
            return NULL;
        } 
    }
};

int main(){
    
    //Approach 1: Recursive O(n)
    /*
    Check if the current node val is the element that we are looking for. If yes return its address.
    If no, give a recursive call to its left and right subtree.
    Check if the returned address is other than null ptr, if yes return that address.
    Base case : If node address reaches null, return nullptr
    //In end, add one more condition : in case not found, return nullptr.
    */

   //Approach 2: Recursive 
   
    //If the given tree is balanced, then the time complexity would be O(log n)
    //If the given tree is not balanced, then the worst case could be if it is built like a chain, hence O(n)
   /*
    Base case : If node reaches NULL, return nullptr 

   Check if current node val is the element we are looking for, if yes, then return the address.
   If the key is more than current node value, give a recursive call for right.
   If the key is less than current node value, give a left recursive call for left.
    Store the above returned address in TreeNode* variables.

    Now, check if any of the returned address if other than nullptr, if yes return that address.
    If no, return NULL.

   */
    return 0;
}