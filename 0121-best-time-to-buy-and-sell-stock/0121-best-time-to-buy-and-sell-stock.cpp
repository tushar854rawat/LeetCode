class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]-mini);
        }
        return maxi;
    }
};