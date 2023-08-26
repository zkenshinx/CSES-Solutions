#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result << 1) % mod;
    }
    cout << result << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n;
    cin >> n;

    solve(n);
    return 0;
}