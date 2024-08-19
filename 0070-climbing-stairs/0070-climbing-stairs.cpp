class Solution {
public:
    int f(int ind,vector<int>&dp){
        if(ind<0){
            return 0;
        }

        if(ind==0){
            return 1;
        }

        if(dp[ind]!=-1) return dp[ind];

        int ans = f(ind-1,dp)+f(ind-2,dp);
        return dp[ind] = ans;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans = f(n,dp);
        return ans;
    }
};