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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root==NULL)
        {
            TreeNode* news=new TreeNode(x);
            return news;
        }
        else if(root->val > x)
        {
            if(root->left==NULL)
            {
                root->left=insertIntoBST(root->left,x);

            }
            else {
                insertIntoBST(root->left,x);
            }

        }
        else
        {
             if(root->right==NULL)
            {
                root->right=insertIntoBST(root->right,x);

            }
            else
            {
                insertIntoBST(root->right,x);
                
            }

        }
        return root;
        
    }
};