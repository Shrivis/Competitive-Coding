class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        if (!node) return;
        int lVal=0, rVal=0, lSum=0, rSum=0;
        if(node->left) lVal = node->left->data;
        if(node->right) rVal = node->right->data;
        toSumTree(node->left);
        if (node->left) lSum = node->left->data;
        toSumTree(node->right);
        if (node->right) rSum =  node->right->data;
        node->data = lSum+rSum+lVal+rVal;
        // return node;
    }
};