//-----------------------N-Queen (place queen such a way no queen can attack each other)

class Solution {
public:
    bool isSafe(int row,int col,vector<string> res,int n){
        int i=row;
        int j=col;

        while(i>=0 && j>=0){
            if(res[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        while(j>=0){
            if(res[i][j]=='Q'){
                return false;
            }
            j--;
        }
        i=row;
        j=col;
        while(i<n && j>=0){
            if(res[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int col,vector<string> &res,int n,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(res);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,res,n)){
                res[row][col]='Q';
                solve(col+1,res,n,ans);
                res[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n);
        string str(n,'.');
        for(int i=0;i<n;i++){
            res[i]=str;
        }
        solve(0,res,n,ans);
        return ans;
    }
};