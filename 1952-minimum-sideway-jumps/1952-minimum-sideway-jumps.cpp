class Solution {
public:
    int f(vector<int>&arr,int currlane,int currpos,vector<vector<int>>&dp){
        if(currpos==arr.size()-1){
            return 0;
        }
        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];
        if(arr[currpos+1]!=currlane){
            return f(arr,currlane,currpos+1,dp);
        }
        else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane!=i && arr[currpos]!=i){
                    ans = min(ans,1+f(arr,i,currpos,dp));
                }
            }
            return dp[currlane][currpos] = ans;
        }
    }
    int minSideJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(4,vector<int>(n,-1));
        return f(arr,2,0,dp);
    }
};