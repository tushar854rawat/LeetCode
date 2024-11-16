class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;  // Result to store levels
        if (!root) return res;   // Handle case where root is NULL

        queue<TreeNode*> q;      // Queue for BFS
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            vector<int> level;         // To store the current level's values

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                // Add the current node's value
                level.push_back(temp->val);

                // Add left and right children to the queue if they exist
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            // Add the current level to the result
            res.push_back(level);
        }

        return res;
    }
};
