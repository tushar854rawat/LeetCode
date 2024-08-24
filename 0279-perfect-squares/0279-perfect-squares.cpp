class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0)
            return 0;

        if(dp[n]!=-1) return dp[n];
        int sum = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int temp = i*i;
            sum = min(sum,1+f(n-temp,dp));
        }
        return dp[n] = sum;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};