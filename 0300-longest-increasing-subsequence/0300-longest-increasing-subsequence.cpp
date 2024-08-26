class Solution {
public:
    int f(int curr,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(curr==nums.size()){
            return 0;
        }
        
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int incl = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            incl = 1+f(curr+1,curr,nums,dp);
        }
        int exe = 0+f(curr+1,prev,nums,dp);
        return dp[curr][prev+1] = max(incl,exe);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return f(0,-1,nums,dp);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr;prev>=-1;prev--){
                int incl = 0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    incl = 1+dp[curr+1][curr+1];
                }
                int exe = 0+dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,exe);
            }
        }
        return dp[0][0];
    }
};