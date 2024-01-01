//---------------------------------Approach I- O(N) space

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*,int> mp;
    while(head1!=NULL && head2!=NULL){
        mp[head1]++;
        mp[head2]++;
        if(mp[head1]==2){
            return head1->data;
        }else if(mp[head2]==2){
            return head2->data;
        }
     
        head1=head1->next;
        head2=head2->next;
    }
    
    while(head1!=NULL){
        mp[head1]++;
        if(mp[head1]==2){
            return head1->data;
        }
        head1=head1->next;
    }
    while(head2!=NULL){
        mp[head2]++;
        if(mp[head2]==2){
            return head2->data;
        }
        head2=head2->next;
    }
    
    
    return -1;
}


//---------------------------------Approach II O(1) space Complexity


//Converting intersection in a loop then find the starting point of loop

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    Node* tmp=head1;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=head2;
    
    Node* fast=head1;
    Node* slow=head1;
    while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head1;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow->data;
            }
        }
    
    
    return -1;
}
