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


//Approach 1: Iterative using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Using queue
        queue<TreeNode*> q1;
        vector<vector<int>> v1;
        if(!root) return v1;
        
        q1.push(root);
        
        while(!q1.empty()){
            int length = q1.size();
            vector<int> v2;
            while(length--){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left){
                    //add to original queue
                    q1.push(node->left);
                }
                if(node->right){
                    q1.push(node->right);
                }
                v2.push_back(node->val);
            }
            v1.push_back(v2);
        }
        
        return v1;
    }
};

int main(){
    
    //Approach 1 : Using queue
    /*
    Initially push the root to the queue.
    Run the loop while the queue is not empty.
        Run a second loop, which will run 'size of current queue' times.
            Pop from the queue, and if it has children, add them to the original queue.
            The Node* which you popped, push that's node value to a vector.
        
        Once, you are out of 2nd loop, push the vector that formed in 2nd loop into the original vector<vector<int>>.
    */
    return 0;
}