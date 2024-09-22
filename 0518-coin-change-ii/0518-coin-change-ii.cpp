class Solution {
public:
    int f(int ind,int t,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==0){
            if(t%arr[0]==0) return 1;
            return 0;
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int incl = 0;
        if(arr[ind]<=t){
            incl = f(ind,t-arr[ind],arr,dp);
        }
        int exe = f(ind-1,t,arr,dp);
        return dp[ind][t] = incl+exe;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};