#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int value;
    Node* next;
    Node(){}
    Node(int val) : value(val), next(nullptr) {}
    void insert(int data, Node*& head) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void print(Node* head) {
        while (head) {
            cout << head->value << " ";
            head = head->next;
        }
    }
};

Node* mergeNodes(Node* head) {
    Node* res = new Node();
    Node* curr = res;
    int sum;
    while(head) {
        if (head->value == 0) {
            Node* newNode = new Node();
            newNode->value = sum;
            newNode->next = NULL;
            sum = 0;
            curr->next = newNode;
            curr = curr->next;
        } else sum += head->value;
        head = head->next;
    }
    return res->next->next;
}

int main() {
    Node* head = new Node(0);
    head->insert(4, head);
    head->insert(2, head);
    head->insert(1, head);
    head->insert(0, head);
    head->insert(1, head);
    head->insert(2, head);
    head->insert(0, head);
    head->insert(2, head);
    head->insert(1, head);
    head->insert(2, head);
    head->insert(0, head);
    head->print(head);
    cout << endl;
    Node* res  = solve(head);
    res->print(res);
    return 0;
}