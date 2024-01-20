class Solution {
  public:
    int solve(int n){
        if(n%4==0){
            return n;
        }
        if(n%4==1){
            return 1;
        }
        if(n%4==2){
            return n+1;
        }
        if(n%4==3){
            return 0;
        }
    }
    int findXOR(int l, int r) {
       return solve(l-1)^solve(r);
    }
};