#include<iostream>
#include<bits/stdc++.h>
//222 Leetcode
/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
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

//Approach 1 : O(n)
class Solution {
public:
    void count(TreeNode* root,int& count1){
        if(!root) return;
        count1++;
        count(root->left,count1);
        count(root->right,count1);
    }
    
    int countNodes(TreeNode* root) {
        int count1=0;
        count(root,count1);
        return count1;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2 : O(logn*logn);
class Solution {
public:
    int countNodes(TreeNode* root) {
        //Checking if the subtree is CBT
        //(go extreme left, and go extreme right, if same height, then CBT)
        int l=0;
        int r=0;
        TreeNode* p1 = root;
        TreeNode* p2 = root;
        
        while(p1){
            p1 = p1 -> left;
            l++;
        }
        
        while(p2){
            p2 = p2 -> right;
            r++;
        }
        
        if(l==r){
            //Subtree is CBT
            return pow(2,l)-1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1: Brute force
    /*
    Use any traversal and keep 1 reference variable for counting. Each time you visit a node, increase counting by 1.
    If root becomes NULL, return NULL;
    */

    //Approach 2 : 
    /*
    Since, it is a complete binary tree, we go to extreme left and extreme right for calculating height.
    (If the subtree is CBT then, extreme left height==extreme right height)
    If same, then return (2^n)-1 where n is height.
    If not, recursive call and return 1(for subtree root node)+count(root->left)+count(root->right);
    */ 
    return 0;
}