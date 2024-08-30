class Solution {
public:
    int f(int n,int j,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n][j]!=-1) return dp[n][j];
        int res = 0;
        for(int k=j;k<5;k++){
            res+=f(n-1,k,dp);
        }
        return dp[n][j] = res;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return f(n,0,dp);
    }
};