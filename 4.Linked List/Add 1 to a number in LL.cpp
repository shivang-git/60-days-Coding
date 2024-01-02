
class Solution
{
    public:
    Node* reverse(Node* head){
        Node* tmp=head;
        Node* prev=NULL;
        Node* next=tmp;
        while(tmp!=NULL){
            next=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=next;
            
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        Node* newhead=reverse(head);
        int sum=0;
        int carry=0;
        Node* tmp=newhead;
        newhead->data=newhead->data+1;
        Node* prev=NULL;
        while(tmp!=NULL){
            sum=tmp->data+carry;
            tmp->data=sum%10;
            carry=sum/10;
            prev=tmp;
            tmp=tmp->next;
        }
        if(carry!=0){
            Node * newnode=new Node(carry);
            prev->next=newnode;
        }
        
        return reverse(newhead);
        
    }
};