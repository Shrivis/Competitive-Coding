
#include <iostream>
using namespace std;

// Function to find the gcd of
// two numbers
int gcd(int a, int b) {
    // Base case
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    if (a % b == 0) return b;

    // Recurse
    return gcd(b, a % b);
}

// Function to print the answer
void printAnswer(int x, int y) {
    // GCD of X and Y
    int val = gcd(x, y);

    // If GCD is power of 2
    if ((val & (val - 1)) == 0)
        cout << "Yes";
    else
        cout << "No";
}

// Driver code
int main() {
    // Given X and Y
    int x = 4;
    int y = 6;

    // Function call
    printAnswer(x, y);

    return 0;
}
