class Solution {
public:
    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return NULL;

        TreeNode* root = new TreeNode(preorder[l]);

        int i = l + 1;

        // find first greater than root
        while (i <= r && preorder[i] < preorder[l]) {
            i++;
        }

        root->left = build(preorder, l + 1, i - 1);
        root->right = build(preorder, i, r);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};