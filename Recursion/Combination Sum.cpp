// -------------------------Recurrsion (Include and exclude)
//can pick one number many times
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& output,int index,int n,vector<int>& candidates,int target){
        if(index==n){
            if(target==0){
                ans.push_back(output);
            }
            return;
        }

        //include case
        if(target>=candidates[index]){
            output.push_back(candidates[index]);
            solve(ans,output,index,n,candidates,target-candidates[index]);
            output.pop_back();
        }

        //exclude case
        solve(ans,output,index+1,n,candidates,target);    
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        
        int n=candidates.size();
        solve(ans,output,0,n,candidates,target);
        return ans;
    }
};