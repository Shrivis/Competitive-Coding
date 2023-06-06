#include <bits/stdc++.h>
using namespace std;

class A {
   public:
    void print() { cout << "called method of class A" << endl; }
};

class B {
   public:
    void print() { cout << "called method of class B" << endl; }
};

class C : public A, public B {};

int main() {
    C obj1;
    obj1.B::print();
    return 0;
}