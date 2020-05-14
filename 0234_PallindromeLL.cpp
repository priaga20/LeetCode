/*Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true*/

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode *s=head,*f=head;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        //reversing second half of LL
        ListNode *curr=s,*prev=NULL,*nex=s;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        ListNode *ptr=prev;
        while(head!=NULL && ptr!=NULL)
        {
            if(head->val==ptr->val)
            {
                head=head->next;
                ptr=ptr->next;
            }
            else
                return false;
        }
        return true;
    }
};