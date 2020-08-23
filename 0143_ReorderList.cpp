/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        ListNode *curr=head, *nex=head->next;
        //finding mid node
        //s will be pointing to mid
        ListNode *s=head,*f=head;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        ListNode *tail=NULL,*tailPrev=NULL;
        while(curr!=s)
        {
            tail=s;
            while(tail->next!=NULL)
            {
                tailPrev=tail;
                tail=tail->next;
            }
            curr->next = tail;
            tail->next=nex;
            tailPrev->next=NULL;
            curr=nex;
            nex=curr->next;
        }
    }
};