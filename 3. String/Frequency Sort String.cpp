class Solution {
public:
    static bool cmp(pair<char, int>& a, 
        pair<char, int>& b) 
{ 
    return b.second < a.second; 
} 
 
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> freq;

        for(auto it:mp){
            freq.push_back({it.first,it.second});
        }
        sort(freq.begin(),freq.end(),cmp);

        for(int i=0;i<freq.size();i++){
            while(freq[i].second>0){
                ans+=freq[i].first;
                freq[i].second--;
            }
          
        }
        
        return ans;

    }
};