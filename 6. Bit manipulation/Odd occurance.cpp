class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xor1=0;
        for(int i=0;i<N;i++){
            xor1=xor1^Arr[i];
        }
        
        long long int cnt=0;
        while(xor1){
            if(xor1&1){
                break;
            }
            cnt++;
            xor1=xor1>>1;
        }
        
        long long int mask=1<<cnt;
        long long int val1=0;
        long long int val2=0;
        for(int i=0;i<N;i++){
            if(mask&Arr[i]){
                val1=val1^Arr[i];
            }else{
                val2=val2^Arr[i];
            }
        }
        
        if(val1>val2){
            return {val1,val2};
        }else{
            return {val2,val1};
        }
        
        
    }
};