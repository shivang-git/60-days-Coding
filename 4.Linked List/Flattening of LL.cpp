//=====================================================Approach space Complexity O(n*m)============================
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

//======================================================Approach II O(1) space complexity=======================