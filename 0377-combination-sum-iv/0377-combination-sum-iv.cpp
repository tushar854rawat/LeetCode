class Solution {
public:
    int f(int t,vector<int>&arr,vector<int>&dp){
        if(t==0){
            return 1;
        }
        if(t<0){
            return 0;
        }
        if(dp[t]!=-1) return dp[t];
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += f(t-arr[i],arr,dp);
        }
        return dp[t] = sum;
    }
    int combinationSum4(vector<int>& arr, int t) {
        vector<int>dp(t+1,-1);
        return f(t,arr,dp);
    }
};