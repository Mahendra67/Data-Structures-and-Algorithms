#include<iostream>
//2 Leetcode
//Add 2 numbers
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Only optimal method ?
        ListNode* head = new ListNode();
        ListNode* ref_head = head;
        int carry = 0;
       while(l1!=NULL || l2!=NULL || carry!=0){
           int sum = 0;
           if(l1!=NULL){
               sum += l1 -> val;
               //Update pointers
               l1 = l1 -> next;
           }
           if(l2!=NULL){
               sum += l2 -> val;
               l2 = l2 -> next;
           }
        
            sum += carry;
            carry = sum/10;
            ListNode* n1 = new ListNode(sum%10);
            ref_head -> next = n1;
            ref_head = n1;
       }
        return head->next;
    }
};

int main(){
    


    //Approach 1:Optimal
    /*
    Traverse through 2 linked list,
    conditions : if 1 becomes null dont add their sum to the overall sum.
    Keep 1 carry variable which will be added to the overall sum. Keep running the loop until you reach both NULL of linked lists
    and carry becomes zero. To get carry divide the overall sum by 10;
    Using 1 dummy node, make links to newly created nodes.
    */
    return 0;
}