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
    void rec(TreeNode* root, string bin, int &sum) {        
        bin += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            for (int i=bin.size()-1; i>=0; --i) 
                sum += (bin[i]-'0')*pow(2, bin.size()-i-1);
            return;
        }
        if (root->left) rec(root->left, bin, sum);
        if (root->right) rec(root->right, bin, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        rec(root, "", sum);
        return sum;
    }
};