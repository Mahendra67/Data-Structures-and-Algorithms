#include<iostream>
#include<bits/stdc++.h>
//328 LeetCode
/*
Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.
*/
using namespace std;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 1
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //Edge case
        if(head==NULL) return NULL;
        //Edge cases for 1 and 2 nodes linked list
        if(head->next==NULL || head->next->next==NULL) return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        //Keep 1 more pointer at curr for linking the odd and even 2 linked lists
        //SInce, head->next will get updated to 2nd odd index, hence we saved it in a variable
        ListNode* link = head->next;
        
        //Connect odd nodes with odd, and even nodes with even 
        while(prev->next!=NULL && curr->next!=NULL){
            prev -> next = curr -> next;
            curr -> next = prev -> next -> next;
            prev = prev -> next;
            curr = curr -> next;
        }
        
        //Now, connect the 2 linked lists
        //prev pointer stores the address of last odd node linked list
        prev -> next = link;
        
        return head;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    

    //Approach 1
    /*
    Connect all odd-indices nodes and even-indices nodes seperately.
    Join the last node of odd-index linkedlist with the head of the even-index nodes linkedlist.
    */
    return 0;
}