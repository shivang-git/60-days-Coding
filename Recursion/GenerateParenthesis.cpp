// -------------------------------------Recursion
/*
In this we perform recurssion and backtracking 
add "(" if open is less than n,
and add ")" if close is less than open, 
having  the BASE_CASE= open==n && close==n in this push output in ans array
                  1 "(" 0
                    / \
    adding open  "((" "()" adding close
            / \           / 
         "(((" "(()"     "()("
*/


class Solution {
public:
    void addparenthesis(int n,vector<string> &ans,int open,int close,string &output){
        if(open==n && close==n){
            ans.push_back(output);
            return;
        }

        if(open<n){
            output+='(';
            addparenthesis(n,ans,open+1,close,output);
            output.pop_back();
        }
        if(close<open){
            output+=')';
            addparenthesis(n,ans,open,close+1,output);
            output.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output="";
        int open=0;
        int close=0;
        addparenthesis(n,ans,open,close,output);
        return ans;
    }
};