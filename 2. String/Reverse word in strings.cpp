#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){
            string word="";
            while(s[i]!=' ' && i<s.size()){
                word+=s[i++];
            }
            if(word.size()!=0){
                ans=word+' '+ans;
            }
        }
        ans.pop_back();

        return ans;
    }
};