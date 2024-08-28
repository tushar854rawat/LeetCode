class Solution {
public:
    int f(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        if(i>=a.length()) return b.length()-j;
        if(j>=b.length()) return a.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        if(a[i]==b[j]) {
            return f(a,b,i+1,j+1,dp);
        }
        else{
            int insertans = 1 + f(a,b,i,j+1,dp);
            int deleteans = 1 + f(a,b,i+1,j,dp);
            int replaceans = 1 + f(a,b,i+1,j+1,dp);

            ans = min(insertans,min(deleteans,replaceans));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1,word2,0,0,dp);
    }
};