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
    void maxDiff(TreeNode* root, int& v, int minVal, int maxVal) {
        if (!root) {
            v = max(v, maxVal-minVal);
            return;
        }
        if (root->val > maxVal) maxVal = root->val;
        if (root->val < minVal) minVal = root->val;
        if (root->left) maxDiff(root->left, v, minVal, maxVal);
        if (root->right) maxDiff(root->right, v, minVal, maxVal);
        v = max(v, maxVal-minVal);
        return;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int v=0;
        maxDiff(root, v, INT_MAX, INT_MIN);
        return v;
    }
};