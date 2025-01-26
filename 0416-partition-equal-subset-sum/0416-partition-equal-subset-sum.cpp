class Solution {
public:
    bool f(int n,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(n<0 && tar!=0) return false;
        if(tar==0) return true;
        if(tar<0 || n<0) return false;
        if(dp[n][tar] != -1) return dp[n][tar];

        int incl = f(n-1,tar-nums[n],nums,dp);
        int exe = f(n-1,tar,nums,dp);
        return dp[n][tar] = incl || exe;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(n-1,sum/2,nums,dp);
    }
};