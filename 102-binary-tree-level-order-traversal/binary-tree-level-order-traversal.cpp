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
   int level(TreeNode* root)
   {
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
   }
   void nthlevel(TreeNode*root,int curr,int target,vector<vector<int>>&v)
   {
    if(root==NULL) return;
    v[curr].push_back(root->val);
    nthlevel(root->left,curr+1,target,v);
    nthlevel(root->right,curr+1,target,v);
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> v;
    int n = level(root);
    v.resize(n); 
    nthlevel(root, 0, 0, v);
    return v;
}

};