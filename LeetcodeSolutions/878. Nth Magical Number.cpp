class Solution {
    #define ll long long int
    int MOD = 1e9 + 7;
public:
    ll gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
    
    ll lcm(int a, int b) {
        return (a*b)/gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll lo=1, mid, high=1e17, target;
        ll _lcm = lcm(a, b);
        while(lo < high) {
            mid = (lo+high)/2;
            target = mid/a + mid/b - mid/_lcm;
            if (target < n) lo = mid+1;
            else high = mid;
        }
        return high%MOD;
    }
};