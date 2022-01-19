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
    bool isSame(TreeNode* r, TreeNode* s) {
        if(r==NULL && s==NULL) return true;
        if(r==NULL || s==NULL) return false;
        return (r->val==s->val)&&isSame(r->left,s->left)&&isSame(r->right,s->right);
    }
    void findPossibleSubArray(TreeNode* root, vector<TreeNode*> &res, int &val) {
        if (root->val == val) res.push_back(root);
        if (root->left) findPossibleSubArray(root->left, res, val);
        if (root->right) findPossibleSubArray(root->right, res, val);
        return;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> possibleSubArray;
        findPossibleSubArray(root, possibleSubArray, subRoot->val);
        for(auto n: possibleSubArray) {
            if (isSame(n, subRoot)) return true;
        }
        return false ;
    }
};