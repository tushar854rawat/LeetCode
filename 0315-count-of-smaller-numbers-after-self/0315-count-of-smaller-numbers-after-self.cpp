class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>sorted;

        for(int i=n-1;i>=0;i--){
            int ind = lower_bound(sorted.begin(),sorted.end(),nums[i])-sorted.begin();
            ans[i]=ind;

            sorted.insert(sorted.begin() + ind, nums[i]);
        }
        return ans;
    }
};