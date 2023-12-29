class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mp; //using hashmap
            for(int j=i;j<s.size();j++){
                mp[s[j]]++; //taking count of all the character in the particular substring
                int mini=INT_MAX,maxi=-1;
                for(auto it:mp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};