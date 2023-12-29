class Solution {
public:
    int maxDepth(string s) {
        int ob=0,cb=0;
        int maxcount=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ob++;
            }else if(s[i]==')'){
                cb++;
            }
            maxcount=max((ob-cb),maxcount);
        }
        return maxcount;
    }
};