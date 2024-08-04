class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int sum = nums[i];
            v.push_back(nums[i]);
            for(int j=i+1;j<n;j++){
                sum += nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        int res = 0;
        const int mod = 1e9+7;
        for(int i=left-1;i<right;i++){
            res=(res+v[i])%mod;
        }
        return res;
    }
};