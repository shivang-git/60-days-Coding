// ------------------------------------Phone keypad problem----------------
//                             23
//                            /   \
//                           abc   def                             
//first get mapping for first index then loop through it and call function for index+1 to get next digit val;

class Solution {
public:
    void solve(vector<string> &ans,string output,string &digits,int index,vector<string> &arr){
        if(index==digits.size()){
            ans.push_back(output);
            return;
        }

        int num=digits[index]-'0';
        string val=arr[num];
        for(int i=0;i<val.size();i++){
            output+=val[i];
            solve(ans,output,digits,index+1,arr);
            output.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output="";
        vector<string> arr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(ans,output,digits,0,arr);
        return ans;
    }
};