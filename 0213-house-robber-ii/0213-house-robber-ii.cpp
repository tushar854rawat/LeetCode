class Solution {
public:
    int f(vector<int>&arr,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1)return dp[n];
        int inc = arr[n]+f(arr,n-2,dp);
        int exe = 0+f(arr,n-1,dp); 
        return dp[n] = max(inc,exe);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>a(nums.begin(),nums.end()-1);
        vector<int>dp1(a.size(),-1);
        int rob1 = f(a,a.size()-1,dp1);

        vector<int>b(nums.begin()+1,nums.end());
        vector<int>dp2(b.size(),-1);
        int rob2 = f(b,b.size()-1,dp2);

        return max(rob1,rob2);
    }
};