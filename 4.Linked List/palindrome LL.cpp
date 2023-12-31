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
//using O(N) space
       //1. find mid of linked list
       //2.reverse the first half
       //3.compare both linked list;
    ListNode* midele(ListNode*head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        //using recurrsion
        //return head if 1element or null
        if(head==NULL || head->next==NULL){
            return head;
        }

        //store new head after base case hit.
        ListNode* newhead=reverseList(head->next);
        ListNode* next=head->next;
        next->next=head;
        head->next=NULL;
        

        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* mid=midele(head);
        ListNode* newhead=reverseList(mid->next);
        ListNode* tmp1=head;
        ListNode* tmp2=newhead;
        while(tmp2!=NULL){
            if(tmp1->val!=tmp2->val){
                reverseList(newhead);
                return false;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        reverseList(newhead);

        return true;
    }
};