class Solution {
public:
    void f(int ind,vector<int>&arr,vector<vector<int>>&ans){
        if(ind==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            swap(arr[i],arr[ind]);
            f(ind+1,arr,ans);
            swap(arr[i],arr[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};