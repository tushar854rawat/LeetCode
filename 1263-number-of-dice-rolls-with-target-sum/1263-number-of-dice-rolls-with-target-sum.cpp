#define MOD 1000000007
class Solution {
public:
    int f(int dice,int face,int tar,vector<vector<int>>&dp){
        if(tar<0) return 0;
        if(dice==0 && tar!=0) return 0;
        if(dice!=0 && tar==0) return 0;
        if(dice==0 && tar==0) return 1;
        if(dp[dice][tar]!=-1) return dp[dice][tar];
        int ans = 0;
        for(int i=1;i<=face;i++){
            ans = (ans + f(dice-1,face,(tar-i),dp))%MOD;
        }
        return dp[dice][tar] = ans;
    }
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        return f(n,k,t,dp);
    }
};