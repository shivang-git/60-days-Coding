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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(-1);
        ListNode* ans=res;
        int sum=0;
        int carry=0;
       
        while(l1!=NULL || l2!=NULL || carry!=0){
            sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=carry;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            carry=sum/10;
        }

        return (res->next);
    }
};