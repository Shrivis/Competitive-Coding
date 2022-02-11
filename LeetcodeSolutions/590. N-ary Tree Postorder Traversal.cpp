/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void postorder(Node* root, vector<int> &res) {
        if (!root) return;
        for (auto &n: root->children) postorder(n, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};