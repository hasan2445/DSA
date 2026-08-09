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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int val=f.first->val;
            int hd=f.second.first;
            int lvl=f.second.second;
            mp[hd].insert({lvl,val});
            if(f.first->left) q.push({f.first->left,{hd-1,lvl+1}});
            if(f.first->right) q.push({f.first->right,{hd+1,lvl+1}});

        }
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            auto v=it.second;
            vector<int>x;
            for(auto i:v)
            {
                x.push_back(i.second);
            }
            ans.push_back(x);
        }
        return ans;
    }
};