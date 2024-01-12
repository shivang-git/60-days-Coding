//=======================================Subset without duplicate subset
// here there is no base case for loop will automatically terminate the recurssion push the output to ans;

class Solution {
public:
    void solve( vector<vector<int>> &ans,vector<int> &output,vector<int> &nums,int index){
        ans.push_back(output);
        for(int i=index;i<nums.size();i++){
           if(i>index && nums[i]==nums[i-1]){
               continue;
           }
            output.push_back(nums[i]);
            solve(ans,output,nums,i+1);
            output.pop_back();
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> output;
        solve(ans,output,nums,0);
        return ans;
    }
};