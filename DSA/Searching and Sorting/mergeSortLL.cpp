#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int x): data(x), next(nullptr) {};

    Node* insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = this;
        return newNode;
    }

    void print() {
        Node* itr = this;
        while (itr != NULL) {
            cout<<itr->data<<" ";
            itr = itr->next;
        }
    }
};


Node* merge(Node* firstNode, Node* secondNode) {
    Node* res = new Node(0);
    Node* temp = new Node(0);
    temp = res;
    while (firstNode != NULL && secondNode != NULL) {
        if (firstNode->data <= secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    return res->next;
}

Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (!slow->next && (!fast && !fast->next)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sort(Node* head) {
    if (head->next == NULL) return head;
    Node* mid = middle(head);
    Node* head2 = mid->next;
    mid->next = NULL;
    Node* resList = merge(sort(head), sort(head2));
    return resList;
}

int main(void) {
    Node* head = new Node(6);
    int n[] = {7, 10, 5, -20, 3, 2};
    for (int i = 0; i < 6; i++) {
        head = head->insert(n[i]); 
    }
    head = sort(head);
    head->print();
    return 0;
}
