class Solution {
public:
    int f(vector<int>& arr, int i, int j, vector<vector<int>>&dp) {
        if (i + 1 == j) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int sum = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int currentSum = arr[i] * arr[j] * arr[k] + f(arr, i, k, dp) + f(arr, k, j, dp);
            sum = min(sum, currentSum);
        }
        return dp[i][j] = sum;
    }

    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(arr, 0, arr.size() - 1,dp);
    }
};
