#include<iostream>
//61 LeetCode
/*
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        //Edge case
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        //For length
        ListNode* l = head;
        int count = 0;
        while(l!=NULL){
            l = l -> next;
            count++;
        }
        //Effective value of k
        k = k % count;
        if(k==0) return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* prev;
        ListNode* last;
        
        for(int i=0;i<k;i++){
            p1 = p1 -> next;
        }
        
        while(p1!=NULL){
            prev = p2;
            last = p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        //Prev has the node which will now become the last node
        //Last has the node which will be attached to head
        prev -> next = NULL;
        last -> next = head;
        
        return p2;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //Edge case
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        //For length
        ListNode* l = head;
        int count = 0;
        while(l!=NULL){
            l = l -> next;
            count++;
        }
        //Effective value of k
        k = k % count;
        if(k==0) return head;
        
        ListNode* end = head;
        ListNode* prev;
        
        //To get kth node from end, find (length of ll-k) node (0-indexing from start)
        for(int i=0;i<(count-k);i++){
            prev = end;
            end = end -> next;
        }
        
        while(end->next!=NULL){
            end = end -> next;
        }
        
        //Prev has the node which will now become the last node
        //End has the node which will be attached to head
        //Save prev->next for new head
        ListNode* head2 = prev -> next;
        prev -> next = NULL;
        end -> next = head;
        
        return head2;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    

    //Approach 1: 
    /*
    Find the length of the linked list, and then find the effective rotation.(length%k).
    Now, for finding the kth node from the end, use 2 pointers both starting from head.
    Traverse one pointer k times such that the distance(nodes) between the 2 pointers is k. 
    Now, increment both pointers by 1 node until one pointer reaches NULL. The previous pointer now points to kth 
    node from the end.
    Keep 1 pointer at previous node of kth node from end, and one pointer at last node.
    Connect the last node to head and the previous node to NULL.
    */


    //Approach 2: More optimized
    /*
    Find the length of the linked list, and then find the effective rotation.(length%k).
    Now, for finding the kth node from the end, it will be present at (length-k) position(if end is counted by 0-indexing),
    or it will be present at (length-k+1) index (if end is counted by 1-indexing).
    Keep 1 pointer at previous node of kth node from end, and one pointer at last node.
    Connect the last node to head and the previous node to NULL.
    */
    return 0;
}