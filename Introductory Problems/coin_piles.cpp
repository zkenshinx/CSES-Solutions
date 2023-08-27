#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(int a, int b) {
    bool flag = 2 * a - b >= 0 && 2 * b - a >= 0 &&
        (2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0;
    cout << (flag ? "YES\n" : "NO\n");
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}