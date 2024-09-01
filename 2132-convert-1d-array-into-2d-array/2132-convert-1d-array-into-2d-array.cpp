class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,0));
        if(n*m!=arr.size()){
            return {};
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j]=arr[i * n + j];
            }
        }
        return v;
    }
};