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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        if(root==NULL) return {};
        st.push(root);
        vector<int>ans;
        while(!st.empty())
        {
            auto f=st.top();
            st.pop();
            ans.push_back(f->val);
            if(f->left) st.push(f->left);
            if(f->right) st.push(f->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};