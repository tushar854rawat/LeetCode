class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini = arr[0];
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxi  = max(maxi,arr[i] - mini);
            mini = min(mini,arr[i]);
        }
        return maxi;
    }
};