#include<iostream>
#include<bits/stdc++.h>
//206 LeetCode
//Reverse a given linked list if you are given head node
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    
    stack<int> s1;
    //Add val to stack
    ListNode* node = head;
    
    while(node!=NULL){
        s1.push(node->val);
        node = node->next;
    }
    
    //Now, pop from stack and update it in ll traversing from head node
    ListNode* node2 = head;
    while(node2!=NULL){
        node2->val = s1.top();
        s1.pop();
        node2 = node2 -> next;
    }
    
    return head;
}

//Iterative approach
ListNode* reverseList(ListNode* head) {
    //Iterative and space complexity O(1)
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr!=NULL){
        ListNode* temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    
    return prev;
}

//Recursive approach
ListNode* reverseList(ListNode* head) {
    //Recursive
    if(head==NULL) return NULL;
    
    ListNode* head2 = NULL;
    
    //Base case
    if(head->next==NULL){
        ListNode* head2 = head;
        return head2;
    }
    
    //recursive call
    head2 = reverseList(head->next);
    
    //work (is under recursive call, since we want to traverse in reverse)
    ListNode* temp = head -> next;
    temp -> next = head;
    //Break the previous link
    head -> next = NULL;
    
    return head2;
}

int main(){
    

    //Approach 1 - Rather than changing the links, reverse the data present in it
    /*
    Using stack, traverse from head node to last node (until node!=NULL), and push node-> val into the stack.
    Now, traverse again from head node to last node, while popping from stack and updating it into the node->val.
    */

   //Approach 2: Iterative
   /*
    Keep 3 pointers, one prev node that is initialized to NULL, current pointer which will be initialized to head.
    And temp pointer which will be initialized to curr-> next, so that after changing curr-> next, we don't lost the reference to next node.
    Now, traverse till curr node becomes null. Change curr->next to prev pointer. and update prev to curr, and curr to temp.
   */

    //Approach 3: Recursive
    /*
    Use recursive call to get to 2nd last node of the linked lists. (In last recursive call for last node, 
    Store the last node in head2 variable for returning the head and return;)
    Then, Make the reverse link by node -> next -> next =  node;
    Then, destroy the old link by node -> next = NULL;
    Edge case for no nodes.
    */

    return 0;
}