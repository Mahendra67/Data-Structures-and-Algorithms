#include<iostream>
#include<bits/stdc++.h>
//124 Leetcode
/*
Binary Tree Maximum Path Sum
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

//Approach 1 : Recursive
class Solution {
public:
    int maxPath(TreeNode* node,int& maxi){
        //Base 
        if(!node) return 0;
        
        //Find largest sum path of left and right subtree
        int ls = maxPath(node->left,maxi);
        int rs = maxPath(node->right,maxi);
        
        //Also, consider the case if both the children nodes are negative
        //We dont want to add them to our consideration, as it will always reduce the max.
        //Hence, if you find both children to be negative, return 0;
        ls = max(ls,0);
        rs = max(rs,0);
        
        //Condition
        //Update if you find larger path sum than maxi
        if((ls + rs + node->val)>maxi){
            maxi = ls + rs + node->val;
        }
        
        //Return the node->val and maximum sum path from left subtree or right subtree
        return node->val + max(ls,rs);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        
        //Return the maxi
        return maxi;
        
    }
};

int main(){
    

    //Approach 1: Recursive
    /*
    Initialize one global variable (maxi) to INT_MIN for storing max path sum.

    IN recursion,
        Base case : Return 0, if you reach NULL.

        Store max path sum of left subtree and max path sum of right subtree.
        If any of the above 2 variables gives -ve value, change it to zero. Since adding negative numbers to the path
        will decrease the max sum. 

        If the sum of node->val + (max path of left subtree) + (max path of right subtree) is greater than maxi, update maxi to this new sum.

        Return only the node->val and max of (max sum path of left subtree and max sum path of right subtree)
    */
    return 0;
}