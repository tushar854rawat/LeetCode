class Solution {
public:
    void dfs(int curr,int n,vector<int>&ans){
        if(curr>n){
            return;
        }
        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            dfs(curr*10+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        for(int i=1;i<=9;i++){
            dfs(i,n,v);
        }
        return v;
    }
};