#include <bits/stdc++.h>
using namespace std;

double oupterProduct(double X1, double Y1, double X2, double Y2) {
    return X1 * Y2 - X2 * Y2;
}

bool isInside(vector<int> x, vector<int> y, int xp, int yp) {
    double cop1, cop2, cop3;
    cop1 = oupterProduct(x[1] - x[0], y[1] - y[0], xp - x[0], yp - y[0]);
    cop2 = oupterProduct(x[2] - x[1], y[2] - y[1], xp - x[1], yp - y[1]);
    cop3 = oupterProduct(x[0] - x[2], y[0] - y[2], xp - x[2], yp - y[2]);
    if (((cop1 > 0.0) && (cop2 > 0.0) && (cop3 > 0.0)) ||
        (cop1 < 0.0) && (cop2 < 0.0) && (cop3 < 0.0)) {
        return true;
    } else return false;
}
bool valid(vector<int> x, vector<int> y) {
    float a = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2) * 1.0);
    float b = sqrt(pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2) * 1.0);
    float c = sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2) * 1.0);
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else return true;
}

int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
    vector<int> x{x1, x2, x3};
    vector<int> y{y1, y2, y3};
    if (!valid(x, y)) return 0;
    bool first = isInside(x, y, xp, yp);
    bool second = isInside(x, y, xq, yq);
    if (first and !second) return 1;
    if (!first and second) return 2;   
    if (first and second) return 3;
    return 4;
}

int main() {
    cout << pointsBelong(0, 0, 2, 0, 4, 0, 2, 0, 4, 0);
    return 0;
}