class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                char ch=s[i]+32;
                cout<<ch<<endl;
                s1+=ch;
            }else if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                s1+=s[i];
            }
        }
        int start=0;
        int end=s1.size()-1;
        while(start<=end){
            if(s1[start]!=s1[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};