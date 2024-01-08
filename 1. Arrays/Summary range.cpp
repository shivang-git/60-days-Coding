class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return {{to_string(nums[0])}};
        }
        vector<string> ans;
        int i=0;
        int j=0;
        while(i<nums.size()){
            j=i;
            while(j+1<nums.size() && nums[j+1]==nums[j]+1){
                j++;
            }
            if(i==j){
                ans.push_back(to_string(nums[i]));
                i++;
            }else{
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i=j+1;
            }
            
        }
        return ans;
    }
};