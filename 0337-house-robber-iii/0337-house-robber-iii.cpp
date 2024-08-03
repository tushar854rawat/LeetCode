/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = f(root);
        return max(res[0],res[1]);
    }
private:
    vector<int> f(TreeNode * root){
        if(root==NULL){
            return {0,0};
        }

        vector<int> lsub = f(root->left);
        vector<int> rsub = f(root->right);

        int take = root->val+lsub[1]+rsub[1];
        int notake = max(lsub[0],lsub[1])+max(rsub[0],rsub[1]);

        return {take,notake};
    }
};