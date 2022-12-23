#include<iostream>
// Leetcode 24
/*
Swap nodes in pair
*/
using namespace std;


// Definition for singly-linked list.
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
    ListNode* swapPairs(ListNode* head) {
        //Edge case
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        ListNode* prev = head;
        ListNode* curr = prev->next;
        //One more pointer to update the link between pairs
        ListNode* link = NULL;
        
        //Update head
        head = head -> next;
        
        while(curr!=NULL){
            ListNode* forw = curr -> next;
            curr -> next = prev;
            prev -> next = forw;
            //To connect with last pair
            if(link!=NULL){
                link -> next = curr;
            }
            //Swap since changing next of listNodes will not change the address of prev and curr pointer.
            //Hence, we need to manually change them
            /*
            1   ->   2 -> 3 -> 4
            |        |
            prev     curr

            After changing the links
            2     ->      1   -> 3 -> 4
            |             |
            curr          prev
            */
            swap(curr,prev);
            
            //Update pointers 
            link = curr;
            prev = prev -> next -> next;
            if(prev==NULL) break;
            curr = curr -> next -> next;
        }

        return head;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}