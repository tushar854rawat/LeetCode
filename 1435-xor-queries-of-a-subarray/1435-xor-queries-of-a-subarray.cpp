class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int ans = 0;
            for(int j=a;j<=b;j++){
                ans ^= arr[j];
            }
            res.push_back(ans);
        }
        return res;
    }
};