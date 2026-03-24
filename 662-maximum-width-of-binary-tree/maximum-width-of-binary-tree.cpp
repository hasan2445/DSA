class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(root==NULL) return 0;

        q.push({root,0}); 
        int ans=0;

        while(!q.empty())
        {
           int sz=q.size();
           long long base = q.front().second; 
           long long mn=1e18;
           long long mx=-1e18;

           while(sz--)
           {
            auto f=q.front();
            q.pop();
            TreeNode* node=f.first;
            long long idx=f.second - base; 

            mn=min(mn,idx);
            mx=max(mx,idx);

            if(node->left) q.push({node->left,2*idx});
            if(node->right) q.push({node->right,2*idx+1});
           }

           ans=max(ans,(int)(mx-mn+1));
        }
        return ans;
    }
};