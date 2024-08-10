class Solution {
public:
    int f(int ind,vector<int>&arr,int amount,vector<vector<int>>&dp){
        if(ind==0){
           if(amount%arr[ind]==0) return amount/arr[0];
           return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake = 0 + f(ind-1,arr,amount,dp);
        int take = INT_MAX;
        if(arr[ind]<=amount){
            take = 1 + f(ind,arr,amount-arr[ind],dp);
        }
        return dp[ind][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int a = f(n-1,coins,amount,dp);
        if(a >= 1e9){
            return -1;
        }
        return a;
    }
};