class Solution {
public:
    int mx=INT_MIN;
    
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        return root->val + max(0, max(height(root->left), height(root->right)));
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left = max(0, height(root->left));
        int right = max(0, height(root->right));
        
        mx=max(mx,root->val + left + right);
        maxPathSum(root->left);
        maxPathSum(root->right);
        return mx;
    }
};
