class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> result;
        string res="";
        int idx=0;
        while(idx < s.size()) {
            if (isdigit(s[idx])) {
                int num=0;
                while(isdigit(s[idx])) {
                    num = 10*num + (s[idx]-'0');
                    idx++;
                }
                idx--;
                nums.push(num);
            } else if (s[idx] == '[') {
                result.push(res);
                res="";
            } else if (s[idx] == ']') {
                string tmp = result.top();
                int num = nums.top();
                result.pop();
                nums.pop();
                for (int i=0; i<num; ++i) tmp.append(res);
                res = tmp;
            } else {
                res += s[idx];
            }
            idx++;
        }
        return res;
    }
};