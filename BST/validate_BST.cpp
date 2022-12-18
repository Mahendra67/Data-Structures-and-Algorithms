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


//Approach 1: Using Vector and Inorder traversal
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& v1){
        if(!root) return;
        
        //Left
        inOrder(root->left,v1);
        
        v1.emplace_back(root->val);
        
        //Right
        inOrder(root->right,v1);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> v1;
        
        //Add every root value in vector
        inOrder(root,v1);
        
        //Check if it is in ascending order
        //If no, then not BST
        int size = v1.size();
        
        for(int i=0 ; i < size-1 ; i++){
            if(v1[i] >= v1[i+1]){
                return false;
            }
        }
        return true;
        
    }
};

//Approach 2: Checking if the root->val is in range
class Solution {
public:
    bool isValidBST(TreeNode* root,long int range_min,long int range_max){
        //Base
        if(!root) return true;
        
         //Left
        //Everything on left should be less than root->val 
        bool s1 = isValidBST(root->left,range_min,root->val);
        
        
        //Work
        if(root->val >= range_max || root->val <= range_min){
            return false;
        }
        
        //Right
        bool s2 =isValidBST(root->right,root->val,range_max);
        
        return s1 && s2;
    }
    
    bool isValidBST(TreeNode* root) {        
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};

int main(){
    

    //Approach 1: Using vector and inorder traversal
    /*
    Do inorder traversal and store every element in a vector.
    
    Now, check if the given vector is in ascending order, if yes then it is BST.
    If no, then it is not a BST.

    */


   //Approach 2: Checking is the current node value is in range
   /*
   Set default range to LONG_MIN and LONG_MAX.

   In recursion, send the arguments would be root, min_range and max range.
        Base:   If root becomes NULL then return true.

        Give a left recursive call with updating max_range to current node's value.
        Since everything on the left should be less than current node's value.

        Now, check if the current node value is in range 
        (Also, for duplicate include =)
        {Since, you included =, in starting we have to take LONG_MIN and LONG_MAX as default range.
        As one of the testcase could be INT_MIN. And by above applied logic, it will give wrong value}

        Give a right recursive call with updating min_range to current node's value.
        Since everything on the right should be greater than current node's value.

        Return (left returned value)&&(right returned value)
   */
    return 0;
}