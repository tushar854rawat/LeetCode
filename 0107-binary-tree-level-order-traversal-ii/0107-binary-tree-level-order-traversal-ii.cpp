class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {}; // Handle empty tree
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level
            vector<int> levelValues;  // Store values for this level
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                levelValues.push_back(temp->val);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            ans.push_back(levelValues); // Add current level values
        }
        
        reverse(ans.begin(), ans.end()); // Reverse the result for bottom-up order
        return ans;
    }
};