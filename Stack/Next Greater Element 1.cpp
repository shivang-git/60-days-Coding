// --------------------------------------t.c- O(N^3)-----------------------------
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
              if(nums1[i]==nums2[j]){
                  int maxi=-1;
                  for(int k=j;k<m;k++){
                      if(nums2[j]<nums2[k]){
                        maxi=nums2[k];
                        break;
                      }
                  }
                  ans.push_back(maxi);
              }
            }
           
        }
        return ans;
    }
};

--------------------------------------------t.c O(N^2) using stack-------------------
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size();
        int m=nums2.size();
        stack<int> st;
        vector<int> res(m);
        for(int i=m-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                res[i]=-1;
            }
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }else{
                res[i]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(res[j]);
                }
            }
        }

        return ans;
    }
};