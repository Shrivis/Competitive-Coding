#include <bits/stdc++.h>
using namespace std;



int shyNodes(SinglyLinkedListNode* ll) {
    if (!ll->next) return 0;
    int res = 0;
    SinglyLinkedListNode *prev=nullptr, *curr = ll, *next = ll->next;
    while(curr) {
        if ((prev and curr->data<prev->data) or 
            (next and curr->data<next->data)) {
            res++;
        }
        prev = curr;
        curr = curr->next;
        if (next) next = next->next;
    }
    return res;
}



int main() {

    return 0;
}
