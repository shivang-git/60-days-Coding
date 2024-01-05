// --------------------------------------------------Approach (Using Map data structure)==============================
//steps: Take the traversal of og node in between create node and map og node and copy node 
// then join each copy node into a single LL and also copy random of it.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp1=head;
        unordered_map<Node*,Node*> mp; //tracking each copy node of og node;

        while(tmp1){
            Node* newnode=new Node(tmp1->val);
            mp[tmp1]=newnode;
            tmp1=tmp1->next;
        }
        
        tmp1=head;
        while(tmp1){
            Node* copynode=mp[tmp1];
            copynode->next=mp[tmp1->next];
            copynode->random=mp[tmp1->random];
            tmp1=tmp1->next;
        }

        return mp[head];
    }
};


// ====================================================Approach (Using copynode in between OG node)===================================
// steps:
// 1.create each node copy and insert it after the each og(original) node.
// 2.now point random of each copy node to other copy node..
//3. now detach the copy node from original node.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* tmp=head;
        while(tmp){
            Node* newnode=new Node(tmp->val);
            newnode->next=tmp->next;
            tmp->next=newnode;
            tmp=newnode->next;
        }
        tmp=head;
        while(tmp){
            if(tmp->random){
                tmp->next->random=tmp->random->next;
            }
            tmp=tmp->next->next;
        }

        Node* newhead=head->next;
        Node* oldhead=head;
        Node* currhead=newhead;
        while(currhead->next){
           oldhead->next=currhead->next;
           oldhead=oldhead->next;
           currhead->next=oldhead->next;
           currhead=currhead->next;
        }
        oldhead->next=NULL;
        return newhead;
    }
};