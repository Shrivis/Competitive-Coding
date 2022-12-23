/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#define pii pair<int, int>

class Solution {
   public:
    unordered_map<int, pair<int, int>> hash;
    int MAX;

    int getHeight(TreeNode*& root, int curr) {
        if (!root) return 0;
        int left = getHeight(root->left, curr + 1);
        int right = getHeight(root->right, curr + 1);
        hash[root->val] = {left, right};
        return max(left, right) + 1;
    }

    void update(TreeNode*& root, unordered_map<int, int>& heights, bool check,
                int curr, int h) {
        if (!root) return;
        heights[root->val] = max(curr, h);
        h++;
        int l = hash[root->val].first + h;
        int r = hash[root->val].second + h;
        if (check or (l == r)) {
            update(root->left, heights, true, MAX, h);
            update(root->right, heights, true, MAX, h);
        } else {
            if (l < r) {
                update(root->left, heights, true, MAX, h);
                update(root->right, heights, false, max(curr, l), h);
            } else {
                update(root->left, heights, false, max(curr, r), h);
                update(root->right, heights, true, MAX, h);
            }
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> heights;
        vector<int> res;
        MAX = getHeight(root, 0) - 1;
        update(root, heights, false, 0, -1);
        for (auto query : queries) {
            res.push_back(heights[query]);
        }
        return res;
    }
};

/// Other method Eular tour using preorder

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#define pii pair<int, int>

class Solution {
   public:
    vector<pii> idxs;
    vector<int> depth, prefix_max, suffix_max;

    int getSize(TreeNode*& root) {
        if (!root) return 0;
        return (getSize(root->left) + getSize(root->right) + 1);
    }

    void preorder(TreeNode*& root, int& idx, int curr_depth) {
        // cout<<idx<<endl;
        if (!root) return;
        idxs[root->val].first = idx;
        depth[idx] = curr_depth;
        idx = idx + 1;
        preorder(root->left, idx, curr_depth + 1);
        preorder(root->right, idx, curr_depth + 1);
        idxs[root->val].second = idx - 1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = getSize(root);
        vector<int> res;
        idxs.resize(n + 1);
        prefix_max.resize(n + 1);
        suffix_max.resize(n + 1);
        depth.resize(n + 1);
        int idx = 0;
        preorder(root, idx, 0);
        for (int i = 1; i < n; ++i)
            prefix_max[i] = max(depth[i], prefix_max[i - 1]);
        for (int i = n - 1; i >= 0; --i)
            suffix_max[i] = max(depth[i], suffix_max[i + 1]);
        for (auto q : queries) {
            int l = idxs[q].first, r = idxs[q].second;
            res.push_back(max(prefix_max[l - 1], suffix_max[r + 1]));
        }
        return res;
    }
};