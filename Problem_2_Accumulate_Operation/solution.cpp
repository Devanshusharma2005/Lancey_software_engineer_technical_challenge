#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int f(int x) {
    return x * x;
}

void g(int a[], int b[], int n, int (*op)(int)) {
    for (int i = 0; i < n; ++i) b[i] = op(a[i]);
}

int main() {
    fastio;
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5}, b[n];
    g(a, b, n, f);
    for (int i = 0; i < n; ++i) cout << b[i] << " ";
    cout << '\n';
    return 0;
}
