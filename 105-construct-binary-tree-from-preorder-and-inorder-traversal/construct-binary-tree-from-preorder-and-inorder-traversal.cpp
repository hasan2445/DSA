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
    TreeNode* build(vector<int>& preorder, int& i, int l, int r,
                    unordered_map<int,int>& mp)
    {
        if (l > r) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        int idx = mp[root->val];

        root->left = build(preorder, i, l, idx - 1, mp);
        root->right = build(preorder, i, idx + 1, r, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int i = 0;
        return build(preorder, i, 0, inorder.size() - 1, mp);
    }
};