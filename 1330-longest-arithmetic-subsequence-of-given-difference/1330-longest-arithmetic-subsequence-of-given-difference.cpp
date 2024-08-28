class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans = 0;

        for(int i=0;i<n;i++){
            int temp = arr[i]-(d);
            int res = 0;
            if(dp.find(temp)!=dp.end()){
                res = dp[temp];
            }
            dp[arr[i]] = res+1;

            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};