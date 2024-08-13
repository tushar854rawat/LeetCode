class Solution {
public:
    void f(int ind,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[ind]>target) break;

            ds.push_back(arr[i]);
            f(i+1,target-arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,arr,ds,ans);
        return ans;
    }
};