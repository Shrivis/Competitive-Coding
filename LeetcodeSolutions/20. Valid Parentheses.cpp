class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        char temp;
        for (char c: s) {
            if (c=='(' || c=='[' || c=='{') store.push(c);
            else {
                if (store.empty()) return false;
                temp = store.top();
                if ((temp=='(' && c==')') || (temp=='[' && c==']') || (temp=='{' && c=='}')) store.pop();
                else return false;
            } 
        }
        if (store.empty()) return true;
        return false;
    }
};