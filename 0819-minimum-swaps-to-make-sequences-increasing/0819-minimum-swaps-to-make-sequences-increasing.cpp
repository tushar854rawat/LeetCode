class Solution {
public:
    int f(int ind,vector<int>& nums1, vector<int>& nums2,int swaped,vector<vector<int>>& dp){
        if(ind>=nums1.size()) return 0;
        if(dp[ind][swaped]!=-1) return dp[ind][swaped];

        int prev1 = nums1[ind-1];
        int prev2 = nums2[ind-1];
        
        int ans = INT_MAX;
        //catch
        if(swaped==1)
            swap(prev1,prev2);

        //notswap
        if(nums1[ind]>prev1 && nums2[ind]>prev2)
            ans = f(ind+1,nums1,nums2,0,dp);

        //swap
        if(nums1[ind]>prev2 && nums2[ind]>prev1)
            ans = min(ans,1+f(ind+1,nums1,nums2,1,dp));

        return dp[ind][swaped] = ans; 
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int swaped = 0;
        return f(1,nums1,nums2,swaped, dp);
    }
};