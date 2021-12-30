class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (!(k&1) || k%5 == 0) return -1;
        int num=1, length=1;
        while(num%k != 0) {
            num = (num*10 + 1)%k;
            length++;
        }
        return length;
    }
};