class Solution {
public:
    int f(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.size()) return 0;
        if(j>=b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        if(a[i]==b[j]){
            ans = 1+f(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(f(a,b,i+1,j,dp),f(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string a, string b) {
        int n = a.length(),m = b.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(a,b,0,0,dp);
    }
};