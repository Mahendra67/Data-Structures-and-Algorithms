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

//Approach 1: Iterative using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //Iterative : Using stack
        stack<TreeNode*> s1;
        vector<int> v1;
        
        TreeNode* node = root;
        while(true){
            if(node){
                s1.push(node);
                node = node -> left;
            }else{
                //Node is null
                //If node is null and stack is empty, break
                if(s1.empty()){
                    break;
                }
                node = s1.top();
                s1.pop();
                v1.emplace_back(node->val);
                node = node -> right;
            }
        }
        return v1;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2: Recursive
class Solution {
public:
    void inOrder(TreeNode* root,vector<int>& elements){
        //Base class
        if(root==NULL) return;
        
        //Left Recursive Call
        inOrder(root->left,elements);
        
        //Work
        elements.emplace_back(root->val);
        
        //Right Recursive Call
        inOrder(root->right,elements);
    } 
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> elements;
        
        //Calling
        inOrder(root,elements);
        
        return elements;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1: Iterative using stack
    /*
    Run a loop:
        Start from root node, if node is not empty, push its address into stack and update node to node->left 
        
        Once your node of the subtree becomes NULL,
        pop from the top of the stack, and push it into the vector. 
        Before popping, keep the address of that node is some variable(address).
        Now, upadate the node to that address->right.
        In this else condition(where node==NULL), break out of the loop is stack is empty.

    */

   //Approach 2: Using recursion
    return 0;
}