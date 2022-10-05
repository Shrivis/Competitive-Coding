#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Node {
   public:
    int key;
    string val;
    Node* next;
    Node(pair<int, string> data) : key(data.first), val(data.second), next(nullptr) {}
};

class Map {
    static const int m = pow(2, 5);
    vector<Node*> valarray;

    int hash_function(int key) {
        double x = key * (sqrt(5) - 1) / 2;
        return floor(m * (x - floor(x)));
    }

    public:
    Map() { 
        valarray.resize(m, nullptr);
    }

    void insert(pair<int, string> data) {
        int idx = hash_function(data.first);
        if (valarray[idx] == nullptr) valarray[idx] = new Node(data);
        else {
            Node* itr = valarray[idx];
            while(itr->next) itr = itr->next;
            itr->next = new Node(data);
        }
    }

    string getItem(int key) {
        int idx = hash_function(key);
        if (valarray[idx] == nullptr) return "-1";
        Node* itr = valarray[idx];
        while (itr) {
            if (itr->key == key) return itr->val;
            itr = itr->next;
        }
        return "-1";        
    }

    bool isPresent(int key) {
        int idx = hash_function(key);
        if (valarray[idx] == nullptr) return false;
        Node* itr = valarray[idx];
        while (itr) {
            if (itr->key == key) return true;
            itr = itr->next;
        }
        return false;
    }

    void print() {
        for (auto head: this->valarray) {
            while(head) {
                cout<<head->key<<" : "<<head->val<<endl;
                head = head->next;
            }
        }
    }

    string Delete(int key) {
        int idx = hash_function(key);
        if (this->valarray[idx] == nullptr) {
            return "key not present";
        }
        if (this->valarray[idx]->next == nullptr) {
            if (this->valarray[idx]->key == key) {
                free(valarray[idx]);
                valarray[idx] = nullptr;
                return "deleted " + to_string(key);
            }
        } else {
            Node* prev = valarray[idx];
            Node* curr = valarray[idx]->next;
            while(curr) {
                if (curr->key == key) {
                    prev->next = curr->next;
                    free(curr);
                    return "deleted " + to_string(key);
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return "key not present";
    }
};

int main() {
    Map* new_map = new Map();
    new_map->insert({1, "Vishal Srivastav"});
    new_map->insert({2, "Anuj Sharma"});
    new_map->insert({3, "Suraj Agarwal"});
    new_map->insert({4, "Nidhi Sharma"});
    new_map->print();
    cout<<new_map->getItem(4)<<endl;
    cout<<new_map->getItem(8)<<endl;
    cout << endl;
    cout << new_map->Delete(3) << endl;
    cout << new_map->Delete(2) << endl;
    cout << new_map->Delete(2) << endl;
    cout<<new_map->Delete(1)<<endl;
    cout<<new_map->Delete(15)<<endl;
    cout << new_map->getItem(4) << endl;
    cout << new_map->getItem(2) << endl;
    new_map->print();
    cout << endl;
    return 0;
}