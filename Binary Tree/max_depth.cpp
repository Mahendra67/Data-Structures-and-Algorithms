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

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 1: Recursive 
class Solution {
public:
    int maxDepth1(TreeNode* node){
        //Base
        if(!node){
            return 0;
        }
        
        //left call
        int m = maxDepth1(node->left);
        
        //right call
        int n = maxDepth1(node->right);
        
        return max(m,n)+1;
    }
    
    int maxDepth(TreeNode* root) {
        return maxDepth1(root);
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1: Recursive
    /*
    Give left and right recursive call, if node becomes null then, return 0;
    Remember to store the values returned from left and right recursive calls.
    While returning from a subtree, return the value of left call and right call + 1 of that subtree.
    +1 for that subtree's head.
    */
   
    return 0;
}