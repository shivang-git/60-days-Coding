//=====================================================(Looping and array)Approach space Complexity O(n*m)============================
Node *flatten(Node *root)
{
   vector<int> ans;
   Node* tmp1=root;
   Node* tmp2=root;
   
   while(tmp1){
       ans.push_back(tmp1->data);
       tmp2=tmp1->bottom;
       while(tmp2){
           ans.push_back(tmp2->data);
           tmp2=tmp2->bottom;
       }
       tmp1=tmp1->next;
   }
   sort(ans.begin(),ans.end());
   
   Node* res=new Node(-1);
   Node* tmp=res;
   for(int i=0;i<ans.size();i++){
       
       tmp->bottom=new Node(ans[i]);
       tmp=tmp->bottom;
   }
   
   return res->bottom;
   
}

//======================================================(Recurrsion) Approach II O(1) space complexity=======================
// we use recurrsion to reach last node of linked list  then merge the last two linked list and backtrack back to last linked list node
// it is like merging last two node of linked list and return it as 1 whole and again merge to other last node of linked list;

   // merge last two LL first is list and other list is sorted list
    Node* merge(Node* root,Node* nextroot){
        Node* tmp1=root;
        Node* tmp2=nextroot;
        Node * ans=new Node(-1);
        Node* res=ans;
        while(tmp1 && tmp2){
            if(tmp1->data<tmp2->data){
                ans->bottom=tmp1;
                ans=tmp1;
                tmp1=tmp1->bottom;
            }else{
                ans->bottom=tmp2;
                ans=tmp2;
                tmp2=tmp2->bottom;
            }
        }
        ans->next=NULL;
        if(tmp1){
            ans->bottom=tmp1;
        }else{
            ans->bottom=tmp2;
        }
        
        return res->bottom;
    }
  
  
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL){
        return root;
    }
        
    Node *newhead=flatten(root->next);
    root= merge(root,newhead);
    return root;
    
}