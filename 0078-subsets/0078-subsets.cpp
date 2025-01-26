class Solution {
public:
    void f(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if(ind>=nums.size()){
            ans.push_back(ds);
            return;
        }
        f(ind+1,nums,ds,ans);

        ds.push_back(nums[ind]);
        f(ind+1,nums,ds,ans);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(0,nums,ds,ans);
        return ans;
    }
};