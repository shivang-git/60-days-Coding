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
    int LLen(ListNode* head){
        ListNode* tmp=head;
        int len=0;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }

        int len=LLen(head);
        if(len==n){
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }
        int res=len-n;
        ListNode* tmp=head;
        while(res!=1){
            tmp=tmp->next;
            res--;
        }
        ListNode* del=tmp->next;
        tmp->next=tmp->next->next;
        delete del;
        

        return head;
    }
};