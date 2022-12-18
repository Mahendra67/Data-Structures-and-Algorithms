#include<iostream>
#include<bits/stdc++.h>
//110 LeetCode
/*If the difference of height of left subtree and the height of the right subtree is less than or equal to 1, 
then that tree is balanced tree.*/
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Approach 1: Recursive
class Solution {
public:
    int height(TreeNode* node){
        //base 
        if(!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1+max(rh,lh);   
    }
    
    bool isBalanced(TreeNode* root) {
        //base
        if(!root) return true;
        
        //left call for height
        int lh = height(root->left);
        //right call for height
        int rh = height(root->right);
        
        if(std::abs(lh-rh)>1){
            return false;
        }
        
        //left call
        bool left = isBalanced(root->left);
        //right call
        bool right = isBalanced(root->right);
        
        return right&&left;
    }
};

int main(){
    
    //Approach 1: Recursive
    /*
    Base : IF node becomes null, return true.

    Find the height of the left subtrees(lh) and the height of the right subtree(rh).
    Check if the difference of their height is greater than 1, if yes, then that is not balanced tree, and return false.

    Now, give a right recursive call, and a left recursive call.
    Make sure to store their returned value in a boolean variable.

    Return true if both of them (left and right call) returns true.
    */
    return 0;
}