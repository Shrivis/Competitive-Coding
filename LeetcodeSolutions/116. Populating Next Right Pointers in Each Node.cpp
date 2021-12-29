/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> level;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        if (!root) return root; 
        while(!q.empty()) {
            Node* curr = q.front();
            if (curr == NULL) {
                for (int i=0; i<level.size()-1; ++i)
                    level[i]->next = level[i+1];
                level.clear();
                q.pop();
                if (!q.empty()) curr = q.front();
                else return root;
                q.push(NULL);
                level.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            } else {
                q.pop();
                level.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;
        
    }
};