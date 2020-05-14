/*Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        //using recursion
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* smallHead=reverseList(head->next);
        ListNode* c=head;
        c->next->next=c;
        c->next=NULL;
        return smallHead;        
    }
    
    //using iteration
    /*ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev=NULL,*nex=head;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }*/
};
