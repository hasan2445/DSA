/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,map<TreeNode*,TreeNode*>&par)
    {
        if(root==NULL) return;
        if(root->left)  par[root->left]=root;
        if(root->right) par[root->right]=root;
        parent(root->left,par);
        parent(root->right,par);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>par;
        if(root==NULL) return {};
        parent(root,par);
        set<TreeNode*>s;
        queue<TreeNode*>q;
        s.insert(target);
        vector<int>ans;
        int x=0;
        q.push(target);
        while(!q.empty())
        {
            if(x>k) break;
            int sz=q.size();
            while(sz--)
            {
                
                auto f=q.front();
                q.pop();
                
                if(x==k)
                 {
                  ans.push_back(f->val);
                }
                
                if(f->left && s.find(f->left)==s.end())
                {
                    q.push(f->left);
                    s.insert(f->left);
                }
                if(f->right && s.find(f->right)==s.end())
                {
                    q.push(f->right);
                    s.insert(f->right);
                }
                if(par.find(f)!=par.end() && s.find(par[f])==s.end())
                {
                    s.insert(par[f]);
                    q.push(par[f]);
                }
            }
            x++;
        }
      return ans;
    }
};