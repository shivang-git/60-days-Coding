#include <bits/stdc++.h>
class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int maxlen=0;
        int k=0,j=0;
        for(int i=0;i<s.size();i++){
            int left=i;
            int right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if((right-left)>maxlen){
                    k=left;
                    j=right;
                    maxlen=max(right-left,maxlen);
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if((right-left)>maxlen){
                    j=right;
                    k=left;
                    maxlen=max(right-left,maxlen);
                }
                left--;
                right++;
            }
        }

        while(k<=j){
            ans+=s[k];
            k++;
        }
        return ans;
    }
};