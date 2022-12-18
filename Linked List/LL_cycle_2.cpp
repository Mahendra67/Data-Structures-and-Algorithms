#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *detectCycle(ListNode *head) {
        //Edge case
        //If 1 or 0 nodes in ll
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        
         //Floyd cycle detection algo
        ListNode* slow = head;
        ListNode* fast = head;
        //One more pointer for finding entry point of loop 
        ListNode* entry = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast==slow){
                //Cycle present
                /*This will still be O(n) because following loop will run in last iteration of first loop.
                So,, we can club the time complexity to O(n)*/
                while(entry!=slow){
                    slow = slow -> next;
                    entry = entry -> next;
                }
                if(slow==entry){
                    return slow;
                }
            }
        }
        //Cycle not present
        return NULL;
    }


int main(){
    


    //Approach 1
    /*Use unordered set, and store node address in it. Run it until you find null.
    At each step, check if the node address is already present in the set, if yes, then that node will be the entry point 
    of the loop*/


    //Approach 2
    /*Using floyd cycle detection alogorith*/
    /*Use one more pointer which starts at head. When slow and fast pointer meets, then increase the slow
    and extra pointer by 1 until they meet. The meeting node of the extra pointer and slow pointer will be the 
    entry point of the cycle*/
    return 0;
}