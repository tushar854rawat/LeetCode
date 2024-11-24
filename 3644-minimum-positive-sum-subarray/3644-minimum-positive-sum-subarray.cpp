class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n= nums.size();
        int ans = 1e9;
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j= i;j< min(i+r , n);j++){
                sum += nums[j];
                if(sum>0 and j-i+1>=l){
                    mp[sum]++;
                }
            }
        }
        for(auto it:mp){
            if(it.first < ans){
                ans = it.first;
            }
        }
        return ans == 1e9 ? -1 : ans;
        
    }
};