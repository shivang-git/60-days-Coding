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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* evenhead=head->next; //taking 2nd elment as head of even links
        ListNode* odd=head; //odd link head
        ListNode* even=head->next;
        while(even->next!=NULL){     //run till even->next is not null
            odd->next=odd->next;
            even->next=even->next->next;
            odd=odd->next;
            if(even->next==NULL){   // extra condition for odd as codition will fail if even next is null;
                break;
            }
            even=even->next;
        }

        odd->next=evenhead;
        return head;
    }
};