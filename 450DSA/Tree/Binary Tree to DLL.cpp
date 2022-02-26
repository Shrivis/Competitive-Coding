class Solution
{
    public: 
    void preorder(Node *root, vector<Node*> &res) {
        if (!root) return;
        preorder(root->left, res);
        res.push_back(root);
        preorder(root->right, res);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root) {
        if (!root->right && !root->left) return root;
        if (!root) return root;
        vector<Node*> res;
        Node *temp;
        preorder(root, res);
        // for (auto node: res) cout<<node->data<<" "; cout<<endl;
        root = res[0];
        temp = root;
        temp->left = NULL;
        temp->right = res[1];
        temp = temp->right;
        for (int i=1; i<res.size()-1; ++i) {
            temp->right = res[i+1];
            temp->left = res[i-1];
            temp = temp->right;
        }
        temp->left = res[res.size()-2];
        temp->right = NULL;
        return root;
    }
};
