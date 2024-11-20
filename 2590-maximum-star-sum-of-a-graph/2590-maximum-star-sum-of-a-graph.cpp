class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n); // Adjacency list
        
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res = INT_MIN;

        // Iterate through each node
        for (int i = 0; i < n; i++) {
            // Collect values of neighbors
            vector<int> neighbors;
            for (int neighbor : adj[i]) {
                neighbors.push_back(vals[neighbor]);
            }

            // Sort neighbors in descending order
            sort(neighbors.rbegin(), neighbors.rend());

            // Compute star sum (including the node itself)
            int sum = vals[i];
            for (int j = 0; j < min(k, (int)neighbors.size()); j++) {
                if (neighbors[j] > 0) {
                    sum += neighbors[j];
                }
            }

            // Update the result
            res = max(res, sum);
        }

        return res;
    }
};
