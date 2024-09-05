class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& adj, int src, int des) {
        int nv = adj.size();
        queue<vector<int>> q;
        vector<vector<int>> ans;
        q.push({src});
        
        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            int last = path.back();
            if (last == des) {
                ans.push_back(path);
                continue;
            }
            for (auto x : adj[last]) {
                if (find(path.begin(), path.end(), x) == path.end()) { 
                    vector<int> newpath = path;
                    newpath.push_back(x);
                    q.push(newpath);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& edge) {
        int nv = edge.size();
        vector<vector<int>> adj(nv, vector<int>(0));

        for (int i = 0; i < nv; i++) {
            for (auto j : edge[i]) {
                adj[i].push_back(j);
            }
        }

        int src = 0;
        int des = nv - 1;
        return bfs(adj, src, des);
    }
};
