class Solution {
public:
    int f(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==0){
            if(tar%nums[ind]==0) return tar/nums[0];
            return INT_MAX;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int exe = 0 + f(ind-1,tar,nums,dp);
        int incl = INT_MAX;
        if(nums[ind]<=tar){
            int a = f(ind,tar-nums[ind],nums,dp);
            if(a!=INT_MAX){
                incl = 1 + a;
            }
        }
        return dp[ind][tar] = min(exe,incl);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};