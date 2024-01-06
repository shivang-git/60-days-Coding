class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* tmp=head;
        while(tmp->next){
            if(tmp->val==tmp->next->val){
                tmp->next=tmp->next->next;
            }else{
                tmp=tmp->next;
            }
        }
        return head;
    }
};


// -----------------------------------------------delete those element from ll which have duplicates in LL

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp=head;
        map<int,int> mp;
        while(tmp){
            mp[tmp->val]++;
            tmp=tmp->next;
        }

        ListNode* newhead=new ListNode(-1);
        ListNode* newnode=newhead;
        for(auto it:mp){
            if(it.second==1){
                ListNode* node=new ListNode(it.first);
                newnode->next=node;
                newnode=newnode->next;
            }
        }
        return newhead->next;
    }
};