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
    int len(ListNode* head){
        int i=0;
        ListNode* tmp=head;
        while(tmp){
            i++;
            tmp=tmp->next;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        
        ListNode* lastnode=head;
        int n=1;
        while(lastnode->next!=NULL){
            lastnode=lastnode->next;
            n++;
        }
        
        if(k%n==0){
            return head;
        }
        k=k%n;
        int d=n-k;
        lastnode->next=head;

        ListNode* tmp=head;
        int count=1;
        while(tmp!=NULL){
            if(count==d){
                break;
            }
            count++;
            tmp=tmp->next;
        }
        ListNode* newhead=tmp;
        head=newhead->next;
        newhead->next=NULL;
        
        return head;        
    }
};