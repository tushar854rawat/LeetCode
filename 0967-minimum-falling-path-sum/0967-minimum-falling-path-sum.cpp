class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.size();

        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = matrix[i][j];

                dp[i][j] = dp[i-1][j] + curr;
                if(j>0){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1] + curr);
                }
                if(j<m-1){
                    dp[i][j] = min(dp[i][j],dp[i-1][j+1] + curr);
                }
            }
        }

        int res = INT_MAX;
        for(int j=0;j<m;j++){
            res = min(res,dp[n-1][j]);
        }
        return res;
    }
};