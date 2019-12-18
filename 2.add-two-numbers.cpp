/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *cur1=l1;
        ListNode *cur2=l2;
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        
        int sum=0, carry =0;
        while(cur1 && cur2){
            sum = cur1->val+cur2->val+carry;
            cur->next = new ListNode(sum%10);           
            carry = sum/10;
            cur = cur->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        ListNode *curX = cur1 ? cur1 : cur2;
        while(curX){
            sum = curX->val+carry;
            cur->next = new ListNode(sum%10); 
            carry = sum/10;          
            cur=cur->next;
            curX=curX->next;
        }
        if(carry) {
            cur->next = new ListNode(1);
            cur->next->next=NULL;
        }
        return res->next;
    }
};
// @lc code=end

