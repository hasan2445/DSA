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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        int flag=0;
        vector<vector<int>>ans;
        while(!q.empty())
        {
            int sz=q.size();
            flag=!flag;
            vector<int>v;
            while(sz--)
            {
                TreeNode* f=q.front();
                q.pop();
                if(f!=NULL) v.push_back(f->val);
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
            }
            if(!flag)
            {
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};