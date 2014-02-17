/*
Add Two Numbers 
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode * addup(ListNode* l1,ListNode *l2,int a)
    {
        ListNode *sum=new ListNode(0);
        if(l1!=NULL&&l2!=NULL)
        {
        
        
        sum->val=(l1->val+l2->val+a)%10;
        a=(l1->val+l2->val+a)/10;
        sum->next=addup(l1->next,l2->next,a);
        return sum;
        }
        else
        {
            if(l1==NULL&&l2!=NULL)
            {
                sum->val=(l2->val+a)%10;
                a=(l2->val+a)/10;
                sum->next=addup(NULL,l2->next,a);
                return sum;
            }
            else
            {
                if(l1!=NULL&&l2==NULL)
                {
                    sum->val=(l1->val+a)%10;
                    a=(l1->val+a)/10;
                    sum->next=addup(l1->next,NULL,a);
                    return sum;
                    }
                else
                {
                    if(a==0)
                    {
                        return NULL;
                    }
                    else
                    {
                        sum->val=a;
                    }
                }
            }
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addup(l1,l2,0);
       
        
        
    }
};
