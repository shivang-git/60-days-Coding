// ===============================Approach 1 (Iterative way)==============
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


// ===========================Approach 2 (Recursive)===============
class Solution
{
    public:
    int addcarry(Node* head){
        if(head==NULL){
            return 1;
        }
        int carr=addcarry(head->next);
        head->data+=carr;
        if(head->data<10){
            return 0;
        }
        head->data=0;
        return 1;
    }
    Node* addOne(Node *head) 
    {
       int carry=addcarry(head);
       if(carry!=0){
           Node* newhead=new Node(carry);
           newhead->next=head;
           return newhead;
       }
       return head;
        
    }
};


