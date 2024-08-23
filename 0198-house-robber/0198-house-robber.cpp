class Solution {
public:
    int f(vector<int>&nums,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int inc = nums[n]+f(nums,n-2,dp);
        int exc = 0+f(nums,n-1,dp);
        return dp[n] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        // vector<int>dp(n,0);
        // return f(nums,n-1,dp);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     int inc = nums[i]+dp[i-2];
        //     int exe = 0+dp[i-1];
        //     dp[i] = max(inc,exe);
        // }
        // return dp[n-1];
        int prev0 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        int sum = 0;
        for(int i=2;i<n;i++){
            int incl = nums[i]+prev0;
            int exe = 0+prev1;
            sum = max(incl,exe);
            prev0=prev1;
            prev1=sum;
        }
        return prev1;
    }
};