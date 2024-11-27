class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis){
        vis[node] = 1;
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjls(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls, vis);
            }
        }
        return cnt;
    }
};