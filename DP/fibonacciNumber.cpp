class Solution {
public:
    // int func(int n,vector<int> &dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     dp[n]=func(n-1,dp)+func(n-2,dp);
    //     return dp[n];
    // }
    int fib(int n) {
        vector<int> dp(n+1);
        // for(int i=0;i<=n;i++){
        //     dp[i]=-1;
        // }
        // return func(n,dp);
        if(n<=1) return n;
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        int prev1=1;
        int prev2=0;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};