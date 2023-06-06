#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val, size;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    void insert(TreeNode*& root, int val) {
        if (!root) root = new TreeNode(val);
        else if (root->val < val)
            insert(root->right, val);
        else
            insert(root->left, val);
    }
};

pair<int, int> sum(TreeNode* root) {
    pair<int, int> p = make_pair(1, 0);
    if (root->left) {
        pair<int, int> ptemp = sum(root->left);

        p.second += ptemp.first + ptemp.second;
        p.first += ptemp.first;
    }
    if (root->right) {
        pair<int, int> ptemp = sum(root->right);

        p.second += ptemp.first + ptemp.second;
        p.first += ptemp.first;
    }
    root->size = p.first;
    return p;
}


void getResult(TreeNode* root, int target, int distancesum, int n, int &ans) {
    if (root->val == target)  ans = distancesum;
    if (root->left) {
        int tempsum = distancesum - root->left->size + (n - root->left->size);
        getResult(root->left, target, tempsum, n, ans);
    }
    if (root->right) {
        int tempsum = distancesum - root->right->size + (n - root->right->size);
        getResult(root->right, target, tempsum, n, ans);
    }
}

int main() {
    int n;
    cin>>n;
    int res = 0, ans = 0;
    TreeNode* root = nullptr;
    for (int i=0; i<n; ++i) {
        int data;
        cin>>data;
        root->insert(root, data);
        pair<int, int> p = sum(root);
        int totalnodes = p.first;
        getResult(root, data, p.second, totalnodes, ans);
        res += ans;
        cout<<res<<endl;
    }
    return 0;
}