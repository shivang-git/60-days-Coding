// ===========================================O(N) two pointer======================
class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        struct Node*tmp=head;
        struct Node*front=tmp;
        while(tmp && tmp->next){
            front=tmp->next;
            while(front!=NULL && front->data==tmp->data){
                front=front->next;
            }
            tmp->next=front;
            if(front){
                front->prev=tmp;
            }
            tmp=tmp->next;
        }
        return head;
    }
};