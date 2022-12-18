#include<iostream>
//19 leetcode
//Remove nth node from the linked list
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  
};
 
//Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        
        //First find the nth node from the end
        ListNode* i = head;
        ListNode* j = head;
        ListNode* prev = head;
        
        //Moving j n times forward
        for(int i=0;i<n;i++){
            j = j -> next;
        }
        
        while(j!=NULL){
            prev = i;
            i = i -> next;
            j = j -> next;
        }
        
        //Now the nth node address from the end is stored in i
        
        //Check if i is pointing to head, if yes then update head
        if(i==head){
            //Update head to next node 
            head = head -> next;  
        }else{
            prev -> next = i -> next;
        }
        
        return head;
    }
};

int main(){
    


    //Approach 1
    //Use two pointers starting from head
    /*Keep traversing one pointer n times
    Now, traverse both pointers by 1 until the first pointer reaches null
    Now, the second pointer points to nth node from the last.
    To remove, check if it is pointing to head, if yes, then update head.
    else, remove the node
    */
    return 0;
}