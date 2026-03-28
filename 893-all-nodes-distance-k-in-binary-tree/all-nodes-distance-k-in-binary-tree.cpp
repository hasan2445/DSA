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
    void par(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent)
    {
        if(root->left==NULL && root->right==NULL) return;
         if(root->left)
        {
            parent[root->left]=root;
            par(root->left,parent);
        }
        if(root->right)
        {
            parent[root->right]=root;
            par(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        if(root==NULL) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        par(root,parent);
        int x=0;
        vector<int>ans;
        q.push(target);
        unordered_set<TreeNode*> vis; 
        vis.insert(target);
        while(!q.empty())
        {
            int sz=q.size();
            if(x==k)
            {
                break;
            }
            while(sz--)
            {
                auto f=q.front();
                q.pop();
               if(f->left && !vis.count(f->left)) 
               {
                q.push(f->left);
                vis.insert(f->left);
               }
               if(f->right && !vis.count(f->right))
               {
                
                q.push(f->right);
                vis.insert(f->right);
               

               } 
               if(parent.find(f)!=parent.end() && !vis.count(parent[f]) )
               {
                 q.push(parent[f]);
                 vis.insert(parent[f]);
               }

            }
            x++;
        }
        while(!q.empty())
        {
            auto f=q.front();
            ans.push_back(f->val);
            q.pop();
        }
        return ans;

        
    }
};