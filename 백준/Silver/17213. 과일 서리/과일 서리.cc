#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, r, x, y, x_i, y_i; // 분자: x, 분모: y
    cin >> n >> r;
    r -= n;
    x = 1, x_i = n + r - 1;
    y = 1, y_i = n - 1;
    for ( int i = 0; i < n - 1; i++ ) {
        x *= x_i;
        y *= y_i;
        x_i--;
        y_i--;
    }
    cout << x / y;
}