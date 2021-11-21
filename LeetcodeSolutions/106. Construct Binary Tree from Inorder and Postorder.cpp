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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hash;
        int n = inorder.size();
        if (inorder.size() == 0) return nullptr;
        for (int i=0; i<inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return BinaryTree(hash, 0, n, postorder, 0, n);
    }
    
    TreeNode* BinaryTree (unordered_map<int, int>& hash, int is, int ie, vector<int>& postorder, int ps, int pe) {
        // is -> inorder start index, ie -> inorder end index,  ps -> postorder start, pe -> postorder end
        if (is >= ie || ps >= pe) return nullptr;
        TreeNode *root = new TreeNode(postorder[pe-1]);
        int break_point = hash[postorder[pe-1]] - is;
        root->left = BinaryTree(hash, is, is+break_point, postorder, ps, ps + break_point);
        root->right = BinaryTree(hash, is+break_point+1, ie, postorder, ps + break_point, pe-1);
        return root;
        
    }
};

/*
Approach: Recursion
Time Complexity: Big Oh(n)
*/