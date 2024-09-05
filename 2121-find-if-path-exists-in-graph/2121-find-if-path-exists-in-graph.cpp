class Solution {
public:
    bool bfs(vector<vector<int>>&adj,int src,int des){
        int nv=adj.size();
        vector<bool>v(nv,false);
        queue<int>q;
        v[src] = true;
        q.push(src);
        while(!q.empty()){
            if(v[des]==true){
                return true;
            }
            int t = q.front();
            q.pop();
            for(auto x : adj[t]){
                if(v[x] == false){
                    v[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }   
    bool validPath(int n, vector<vector<int>>& edge, int source, int destination) {
        int nv = edge.size();
        vector<vector<int>>adj(n,vector<int>(0));
        for(int i=0;i<nv;i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }

        bool ans = bfs(adj,source,destination);
        return ans ;       
    }
};