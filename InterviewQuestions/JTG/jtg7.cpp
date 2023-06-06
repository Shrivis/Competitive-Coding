Node* lca(Node* root ,int n1 ,int n2 ) {
    if(!root) return NULL;
    if(root->data == n1 or root->data == n2) return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if(left and right) return root;
    else if(left and !right) return left;
    else if(!left and right) return right;
    else return NULL;
}