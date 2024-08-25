class Solution {
public:
    int f(int ind,int s,vector<int>&arr,int maxi,vector<vector<int>>&dp){
        if(ind==arr.size()){
            return 0;
        }
        if(dp[ind][s] != -1) return dp[ind][s];

        int incl = (arr[ind]*s)+f(ind+1,s+1,arr,maxi,dp);

        int exe = 0+f(ind+1,s,arr,maxi,dp);
        maxi = max(incl,exe);
        return dp[ind][s] = maxi;
    }
    int maxSatisfaction(vector<int>& arr) {
        // int n = arr.size();
        sort(arr.begin(),arr.end());
        // int maxi = 0;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return f(0,1,arr,maxi,dp);

        int n = arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int incl = arr[index]*(time+1)+next[time+1];
                int exe = 0+next[time];
                curr[time] = max(incl,exe);
            }
            next=curr;
        }  
        return next[0];
    }
};