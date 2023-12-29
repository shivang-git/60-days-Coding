class Solution {
public:
    string removeOuterParentheses(string s) {
        string  ans="";
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch== '('){
                if(!st.empty()){
                    ans+=ch;
                }
                st.push('(');
            }
            else{
               st.pop();
               if(!st.empty()){
                   ans+=ch;
               }
            }
        }
        return ans;
    }
};