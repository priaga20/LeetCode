/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/




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
    //Alternate solution
    //Conevrt both LL to int numbers, add both the ints, convert result to LL, return new LL
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1, *q=l2;
        ListNode* prev=p;
        int carry=0;
        
        //both p and q are not NULL
        while(p!=NULL && q!=NULL)
        {
            int t=p->val+q->val+carry;
            if(t<=9)
            {
                p->val=t;
                carry=0;
            }  
            else
            {
                p->val=t%10;
                carry=1;
                if(p->next==NULL && q->next==NULL)
                {
                    ListNode* n=new ListNode(1);
                    p->next=n;
                    return l1;
                }
            }
            prev=p;
            p=p->next;
            q=q->next;
        }
        
        //q is NULL
        while(p!=NULL)
        {
            if(!carry)
                return l1;
            else
            {
                int t=p->val+carry;
                if(t<=9)
                {
                    p->val=t;
                    return l1;
                }  
                else
                {
                    p->val=t%10;
                    carry=1;
                    if(p->next==NULL)
                    {
                        ListNode* n=new ListNode(1);
                        p->next=n;
                        return l1;
                    }
                }
                prev=p;
                p=p->next;   
            }
        }
        
        //p is null
        prev->next=q;
        while(q!=NULL)
        {
            if(!carry) 
                return l1;  
            else
            {
                int t=q->val+carry;
                if(t<=9)
                {
                    q->val=t;
                    return l1;
                }  
                else
                {
                    q->val=t%10;
                    carry=1;
                    if(q->next==NULL)
                    {
                        ListNode* n=new ListNode(1);
                        q->next=n;
                        return l1;
                    }
                }
                q=q->next;   
            }
        }
        
        return l1;
    }
};