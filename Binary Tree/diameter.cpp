#include<iostream>
#include<bits/stdc++.h>
//543 Leetcode
/*
Find diameter of a given BT.
Diameter is the longest path between 2 nodes. It doesn't needs to cross the root node
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

//Approach 1: O(n^2)
class Solution {
public:
    int height(TreeNode* node){
        if(!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1+max(rh,lh);
    }
    
    void dia(TreeNode* node,int& max){
        //Base
        if(node==NULL) return;
        
        int lh = height(node->left);
        int rh = height(node->right);
        
        int maxi = lh+rh;
        if(maxi>max){
            max = maxi;
        }
        
        //left call
        dia(node->left,max);
        //right call
        dia(node->right,max);
        return;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        //Since, val can't be smaller than -100
        dia(root,max);
        
        return max;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2: O(n)
class Solution {
public:
    int height(TreeNode* node,int& max){
        if(!node) return 0;
        int lh = height(node->left,max);
        int rh = height(node->right,max);
        
        int maxi = lh+rh;
        if(maxi>max){
            max = maxi;
        }
        //Since, we used max also as variable name, we need to define its scope
        return 1+std::max(rh,lh);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        //Since, val can't be smaller than -100
        height(root,max);
        
        return max;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1: Recursive O(n^2)
    /*
    Initialize global variable max to 0.
    Find height of left subtree + height of right subtree.
    Update max if the above sum is greater than max.
    Now, give left and right call.
    */

   //Appraoch 2: Recursive
   /*
   Since in approach 1, in dia function, at every step we were calculating height of left subtree and height of right subtree,
   which is same as what we did in height function. Hence, we combined the 2 functions together.
   */
    return 0;
}