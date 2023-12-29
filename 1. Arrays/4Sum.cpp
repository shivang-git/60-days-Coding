class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum>target){
                    l--;
                }else if(sum<target){
                    k++;
                }else{
                    vector<int> tmp={nums[i],nums[j],nums[k],nums[l]};
                   
                    ans.push_back(tmp);
                    k++;
                    l--;
                    while( k<l && nums[l]==nums[l+1]){
                        l--;
                    }
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                }
            }
            }
        }
        return ans;
    }
};