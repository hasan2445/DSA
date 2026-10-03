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
        if(root==NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v;
            flag=!flag;
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);

            }
            if(!flag) reverse(v.begin(),v.end());
            ans.push_back(v);
            
        }
        return ans;
    }
};