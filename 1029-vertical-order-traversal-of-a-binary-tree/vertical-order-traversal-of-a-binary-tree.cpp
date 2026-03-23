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
        
        map<int, vector<pair<int,int>>> mp; // hd -> {level, value}
        queue<pair<TreeNode*, pair<int,int>>> q; // node -> {hd, level}

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second;

            mp[hd].push_back({lvl, node->val});

            if(node->left)  q.push({node->left, {hd - 1, lvl + 1}});
            if(node->right) q.push({node->right, {hd + 1, lvl + 1}});
        }

        vector<vector<int>> ans;

        for(auto &it : mp) {
            auto vec = it.second;

            sort(vec.begin(), vec.end(), [](auto &a, auto &b){
                if(a.first == b.first) return a.second < b.second; // value
                return a.first < b.first; // level
            });

            vector<int> col;
            for(auto &p : vec) {
                col.push_back(p.second);
            }

            ans.push_back(col);
        }

        return ans;
    }
};