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
    void inorder(TreeNode* root, vector<int> &res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        TreeNode* node = new TreeNode(res[0]);
        TreeNode* temp = node;
        for(int n: res) {
            temp->right = new TreeNode(n);
            temp = temp->right;
        }
        return node->right;
    }
};