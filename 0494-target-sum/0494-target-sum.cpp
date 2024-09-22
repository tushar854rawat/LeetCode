class Solution {
public:
    int f(int ind,int t,vector<int>& arr,vector<vector<int>>& dp){
        if(t<0) return 0;
        if(ind==0){
            if(t==0 && arr[ind]==0) return 2;
            if(t==0 || arr[ind]==t) return 1;
            return 0;
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int incl = 0;
        if(arr[ind]<=t){
            incl = f(ind-1,t-arr[ind],arr,dp);
        }        
        int exe = f(ind-1,t,arr,dp);
        return dp[ind][t] = incl+exe;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums){
            total += x;
        }
        int t = total-target/2;
        if(total-target<0 || (total-target)%2) return 0;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return f(n-1,(total-target)/2,nums,dp);
    }
};