#include <bits/stdc++.h>

using namespace std;

unsigned long long Karatsuba(unsigned long long a, unsigned long long b) {
    unsigned long long digits;
    unsigned long long lefta, righta, leftb, rightb;
    unsigned long long x1, x2, x3;
    if (a < 10 || b < 10) {
        return a*b;
    }
    string astr = to_string(a);
    string bstr = to_string(b);
    digits = max(astr.length(), bstr.length());
    unsigned long long half = digits/2;
    lefta = stoi(astr.substr(0, half));
    righta = stoi(astr.substr(half, digits-half));
    leftb = stoi(bstr.substr(0, half));
    rightb = stoi(bstr.substr(half, digits-half));
    x1 = Karatsuba(lefta, leftb);
    //cout << "ac is " << x1 << endl;
    x2 = Karatsuba(righta, rightb);
    //cout << "bd is " << x2 << endl;
    x3 = Karatsuba((lefta+righta), (leftb+rightb));
    return x1 * pow(10, 2*half) + (x3-x2-x1) * pow(10, half) + x2;
}

int main()
{
    cout << Karatsuba(1234, 1234);
}