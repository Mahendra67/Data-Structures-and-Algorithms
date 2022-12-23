#include<iostream>
#include<bits/stdc++.h>
//144 LeetCode
//Given the root of a binary tree, return the preorder traversal of it's nodes values
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
 
/*----------------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    void preOrder(TreeNode* root,vector<int>& elements){
        //Using recursion
        //Base case
        if(root==NULL) return;
        
        //Work
        elements.emplace_back(root->val);
        
        //Left Recursive Call
        preOrder(root->left,elements);
        
        //Right Recursive Call
        preOrder(root->right,elements);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elements;
        
        //Call the recursive function
        preOrder(root,elements);
        
        return elements;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2: Iterative 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //Iterative traversal : Using stack
        stack<TreeNode*> s1;
        //Using vector to store all values
        vector<int> v1;
        //Edge case: if root==NULL
        if(!root) return v1;
        s1.push(root);
        
        while(!s1.empty()){
            v1.push_back(s1.top()->val);
            TreeNode* n1 = s1.top();
            s1.pop();
            //Since, we are using stack and this is preorder traversal
            //First push right node, then left, so that left node is on top
            //Also, check if it left and right nodes are present or not
            if(n1->right!=NULL){
                s1.push(n1->right);
            }
            if(n1->left!=NULL){
                s1.push(n1->left);
            }
        }
        return v1;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    

    //Approach 1:Recursive
    /*
    push the value of current TreeNode in vector.
    Give a left call,
    give a right call.

    Base:  if node becomes null, return;
    */
    

    //Approach 2:Iterative, using STACK
    /*
    Push the given node address in stack (if node is not NULL)
    Run a loop (terminate when stack becomes empty)
        Push the TreeNode value which is at top of the stack.
        Store that address in some variable, and pop it from the stack.
        Check if address->right is not NULL -> if yes then, push it into stack.
        Check if address->left is not NULL -> if yes, then, push it into stack.
    Return the vector
    */
    return 0;
}