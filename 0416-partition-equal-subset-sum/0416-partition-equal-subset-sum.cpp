class Solution {
public:
    bool f(int ind,int tar,vector<int>& nums,vector<vector<int>>&dp){
        if(tar<0) return false;
        if(ind>=nums.size() && tar!=0) return false;
        if(tar==0) return true;
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        bool incl = f(ind+1,tar-nums[ind],nums,dp);
        bool exe = f(ind+1,tar,nums,dp);
        return dp[ind][tar] = incl||exe;
    }
    bool canPartition(vector<int>& nums) {
        int tar = 0;
        for(auto x : nums){
            tar+=x;
        }
        if(tar%2==1) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(tar+1,-1));
        return f(0,tar/2,nums,dp);
    }
};