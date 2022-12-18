#include<iostream>
#include<bits/stdc++.h>
//160 Leetcode
//Given 2 heads of singly linked list, return the intersection node if present, else, return null

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //Using unordered_sets
    unordered_set <ListNode*> st;
    
    ListNode* node1 = headA;
    ListNode* node2 = headB;
    
    //Add first ll nodes address to the set
    while(node1 != NULL){
        st.insert(node1);
        node1 = node1 -> next;
    }
    
    //Now check if second ll has same ListNode refernce in their ll
    while(node2 != NULL){
        if(st.find(node2) != st.end()){
            return node2;
        }
        node2 = node2 -> next;
    }
    
    //Not found
    return NULL;
}

int main(){
    
    //Approach 1 : Using unordered sets
    /*
    Traverse thorough 1st linked list and store each node's address in an unordered set.
    Now, traverse thorough 2nd linked list and check if the node's address is already present in the set.
    If the linked lists intersects, then the intersection node's address will be already present.
    */

    return 0;
}