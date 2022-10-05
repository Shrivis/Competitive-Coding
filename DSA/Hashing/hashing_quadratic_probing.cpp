#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Node {
   public:
    int key;
    string val;
    bool is_empty;
    bool deleted;
    Node(pair<int, string> data)
        : key(data.first), val(data.second), is_empty(true), deleted(false) {}
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
        for (int i = 0; i < m; ++i) valarray.push_back(new Node({0, ""}));
    }

    void insert(pair<int, string> data) {
        int i = 0;
        while (true) {
            int idx = (hash_function(data.first) + i) % m;
            if (this->valarray[idx]->is_empty) {
                this->valarray[idx] = (new Node(data));
                this->valarray[idx]->is_empty = false;
                this->valarray[idx]->deleted = false;
                return;
            }
            i++;
        }
    }

    string getItem(int key) {
        int i = 0;
        while (i < m) {
            int idx = (hash_function(key) + i) % m;
            if (this->valarray[idx]->is_empty and !this->valarray[idx]->deleted)
                return "Key not present";
            if (this->valarray[idx]->key == key and
                !this->valarray[idx]->deleted)
                return this->valarray[idx]->val;
            i++;
        }
        return "Key not present";
    }

    bool isPresent(int key) {
        int i = 0;
        while (i < m) {
            int idx = (hash_function(key) + i) % m;
            if (this->valarray[idx]->is_empty and !this->valarray[idx]->deleted)
                return false;
            if (this->valarray[idx]->key == key) return true;
            i++;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < m; ++i) {
            if (this->valarray[i]->is_empty == false)
                cout << this->valarray[i]->key << " " << this->valarray[i]->val
                     << endl;
        }
    }
    string Delete(int key) {
        int i = 0;
        while (i < m) {
            int idx = (hash_function(key) + i) % m;
            if (this->valarray[idx]->is_empty and !this->valarray[idx]->deleted)
                return "can't delete. Element not present";
            if (this->valarray[idx]->key == key and
                !this->valarray[idx]->deleted) {
                this->valarray[idx]->deleted = true;
                this->valarray[idx]->is_empty = true;
                return "Successfully deleted " +
                       to_string(this->valarray[idx]->key);
            }
            i++;
        }
        return "can't delete element not present";
    }
};

int main() {
    Map* new_map = new Map();
    new_map->insert({1, "Vishal Srivastav"});
    new_map->insert({2, "Anuj Sharma"});
    new_map->insert({3, "Suraj Agarwal"});
    new_map->insert({4, "Nidhi Sharma"});
    new_map->print();
    cout << new_map->getItem(4) << endl;
    cout << new_map->getItem(8) << endl;
    cout << endl;
    cout << new_map->Delete(3) << endl;
    cout << new_map->Delete(2) << endl;
    cout << new_map->Delete(2) << endl;
    cout << new_map->Delete(1) << endl;
    cout << new_map->Delete(15) << endl;
    cout << new_map->getItem(4) << endl;
    cout << new_map->getItem(2) << endl;
    new_map->print();
    cout << endl;
    return 0;
}