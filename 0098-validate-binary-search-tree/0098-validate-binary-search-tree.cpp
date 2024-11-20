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
    bool isValidBST(TreeNode* root,long long minval = LLONG_MIN,long long maxval = LLONG_MAX) {
        if(root == NULL){
            return true;
        }
        if(root->val <= minval || root->val >= maxval){
            return false;
        }
        return isValidBST(root->left,minval,root->val) && isValidBST(root->right,root->val,maxval);
    }
};