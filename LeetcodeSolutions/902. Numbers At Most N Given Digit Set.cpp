class Solution {
    // int numbers(vector<string>& digits, int n, string currSum) {
    //     long long val = stoll(currSum);
    //     if (val>n) return 0;
    //     int x = 1;
    //     for (auto& num: digits) {
    //         x += numbers(digits, n, currSum+""+ num);
    //     }
    //     return x;
    // }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // int res = numbers(digits, n, "0");
        // return res-1;
        int count = 0;
        string nums = to_string(n);
        for (int i=1; i<nums.size(); ++i) {
            count += pow(digits.size(), i);
        }
        int i=0;
        while (i<nums.size()) {
            int j=0;
            while(j<digits.size() && digits[j][0]<nums[i]) {
                count += pow(digits.size(), nums.size()-1-i);
                j++;
            }
            if (j==digits.size() || digits[j][0]>nums[i]) break;
            i++;
        }
        if (i==nums.size()) count++;
        return count;
    }
};