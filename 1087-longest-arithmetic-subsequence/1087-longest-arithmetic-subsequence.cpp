class Solution {
public:
    int f(int ind,int diff,vector<int>&nums,unordered_map<int,int>dp[]){
        if(ind<0) return 0;
        if(dp[ind].count(diff)) return dp[ind][diff];
        int ans = 0;
        for(int j=ind-1;j>=0;j--){
            if(nums[ind]-nums[j]==diff){
                ans = max(ans,1+f(j,diff,nums,dp));
            }
        }
        return dp[ind][diff] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        // int n = nums.size();
        // if(n<=2){
        //     return n;
        // }
        // unordered_map<int,int>dp[n+1];
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans = max(ans,2+f(i,nums[j]-nums[i],nums,dp));
        //     }
        // }
        // return ans;

        int n = nums.size();
        unordered_map<int,int>dp[n+1];
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                int c = 1;
                //check
                if(dp[j].count(diff))
                    c = dp[j][diff];
                dp[i][diff]=1+c;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};