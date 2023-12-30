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
    ListNode* reverseList(ListNode* head) {
        //using recurrsion
        //return head if 1element or null
        if(head==NULL || head->next==NULL){
            return head;
        }

        //store new head after base case hit.
        ListNode* newhead=reverseList(head->next);
        //store the element after the old head to make sure changing the next ptr of curr element
        ListNode* next=head->next;
        next->next=head;
        head->next=NULL;
        

        return newhead;
    }

};