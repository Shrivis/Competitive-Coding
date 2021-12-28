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
    int tiltCal(TreeNode* root, int &tilt) {
        if (!root) return 0;
        int l = tiltCal(root->left, tilt);
        int r = tiltCal(root->right, tilt);
        tilt += abs(l-r);
        return root->val + r + l;
    }
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        tiltCal(root, tilt);
        return tilt;
    }
};

// Time O(n)
// Space O(n)