class Solution {
public:
    void f(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(ind==arr.size()){
            return ;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        f(ind+1,target,arr,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,arr,ans,ds);
        return ans;
    }
};