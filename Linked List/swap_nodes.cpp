#include<iostream>
#include<bits/stdc++.h>
//1721 Leetcode
//Swapping nodes in a linked list (ll is 1-indexed)
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

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* p3 = head;
        
        for(int i=1;i<k;++i){
            p2 = p2 -> next;
        }
        //Store kth node from beginning at p3
        p3 = p2;
        
        //To get kth node from the end
        while(p2!=NULL){
            //Stop the iteration such that p2 points to last node and not NULL
            if(p2 -> next == NULL) break;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        //Now, p1 is kth node from the end
        //and p3 stores kth node from beginning
        swap(p1->val,p3->val);
        
        return head;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    //Approach 1 
    /*
    Use three pointers, p1,p2,p3 and every nodes initializes to head
    Find the kth node from the beggining, by iterating any pointer k-1 times (since, it is 1-indexed).
    Using other two nodes, find the kth node from the end. Make sure that the last pointer doesn't reach NULL 
    but stores the address of Last Node.
    Then swap the values of kth node from beginning and kth node from end
    */
    return 0;
}