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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        int ans=0;
        while(!q.empty())
        {
           int sz=q.size();
             long long mn=1e18;
             long long mx=-1e17;
             long long str=q.front().second;
           while(sz--)
           {
            auto f=q.front();
            auto node=f.first;
            long long idx=f.second-str;
            q.pop();
            mn=min(mn,idx);
            mx=max(mx,idx);
            if(node->left) q.push({node->left,2*idx});
            if(node->right) q.push({node->right,2*idx+1});
           }
           ans=max((int)(mx-mn+1),ans);
        }
        return ans;
    }
};