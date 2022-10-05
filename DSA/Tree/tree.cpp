#include <iostream>
#include <queue>
            using namespace std;

class TreeNode {
    int val = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

   public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    void insert(TreeNode*& root, int val) {
        if (!root)
            root = new TreeNode(val);
        else if (root->val < val)
            insert(root->right, val);
        else
            insert(root->left, val);
    }

    void preorder(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    void level_order(TreeNode* root) {
        if (!root) cout << "{}";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    bool search(TreeNode* root, int val) {
        if (!root) return false;
        if (root->val == val) return true;
        if (root->val < val) return search(root->right, val);
        return search(root->left, val);
    }
};

int main() {
    /**
     * Definition for a binary tree node.
     * class TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
     * left(left), right(right) {}
     * };
     */
    TreeNode* root = nullptr;
    root->insert(root, 4);
    root->insert(root, 3);
    root->insert(root, 2);
    root->insert(root, 1);
    root->insert(root, 6);
    root->insert(root, 7);
    root->inorder(root);
    return 0;
}