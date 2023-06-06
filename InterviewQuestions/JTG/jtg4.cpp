
Node* solve(Node* root) {
    if (!root) return NULL;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if (root->data == 0 and !root->right and !root->left) return NULL;
    return root;
}