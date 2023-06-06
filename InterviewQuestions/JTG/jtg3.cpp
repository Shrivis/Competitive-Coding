#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
    void insert(int data, Node* &head) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void print(Node* head) {
        while(head) {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

int getSize(Node* head) {
    int size = 0;
    while(head) {
        head = head->next;
        size++;
    }
    return size;
}

int twinSum(Node* head) {
    int size = getSize(head), res = 0;
    int arr[size];
    for (int i=0; i<size; ++i) {
        arr[i] = head->data;
        head = head->next;
    }
    for (int i=0; i<size/2; ++i) {
        res = max(res, arr[i]+arr[size-i-1]);
    }
    return res;
}

int main() {
    Node* head = new Node(5);
    head->insert(4, head);
    head->insert(2, head);
    head->insert(1, head);
    head->print(head);
    cout<<endl;
    cout<<twinSum(head)<<endl;
    return 0;
}