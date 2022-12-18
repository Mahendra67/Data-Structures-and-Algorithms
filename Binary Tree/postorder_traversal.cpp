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

//Approach 2: Iterative using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v1;
        if(!root) return v1;
        stack<TreeNode*> s1,s2;
        
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        
        while(!s2.empty()){
            v1.push_back(s2.top()->val);
            s2.pop();
        }
        
        return v1;
    }
};

int main(){
    
    //Approach 1:Recursively
    /*
    Base : If node becomes null, return;
    Now, give a left call, then a right call;
    Now, print the result
    */

   //Approach 2: Iteratively using 2 stacks
   /*
   Initally push the root into stack1.
   IN loop,
        Remove the top node address and put it into stack2.
        Now, if this node has left, add into stack1, then if that same node has left node too,
        add it into the stack1.
        terminate the loop when stack1 becomes  empty.
    Now, run a 2nd loop to push every node's address from stack2 and push it into vector until stack2 becomes empty.
   */
    return 0;
}