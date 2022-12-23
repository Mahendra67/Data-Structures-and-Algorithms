#include<iostream>
#include<bits/stdc++.h>
//148 LeetCode
/*Sort List: given head of the linked list, sort it in ascending order*/
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

//Approach 1: Using min heap 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        //Using min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //Add every value of node to heap
        ListNode* p1 = head;
        while(p1){
            pq.push(p1->val);
            p1 = p1 -> next;
        }
        
        //Now update each value according to the min heap
        p1 = head;
        while(p1){
            p1 -> val = pq.top();
            //After updating in linked list, remove from heap
            pq.pop();
            p1 = p1 -> next;
        }
        return head;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    

    //Approach 1: Using min heap
    /*Traverse through each node, and store the value in a min heap.
    Now, traverse again from head to end of linked list while updating node->val to 
    the returned value of top() of the min heap.
    (Top of the min heap will be the minimum value in that heap)*/
    return 0;
}