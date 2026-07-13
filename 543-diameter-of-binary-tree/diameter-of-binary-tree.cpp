class Solution {
public:
    int mx=0;
    
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        mx=max(mx,(height(root->left)+height(root->right)));
        
        
        diameterOfBinaryTree(root->left); 
        diameterOfBinaryTree(root->right);
        
        return mx;
    }
};
