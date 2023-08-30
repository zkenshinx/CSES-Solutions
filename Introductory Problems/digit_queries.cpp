#include <bits/stdc++.h>

using namespace std;

void solve(long long n) {
    long long mult = 1;
    long long nine = 9;
    while (true) {
        long long current = nine * mult;
        if (current < n) {
            n -= current;
            ++mult;
            nine *= 10;
        } else {
            string number = to_string((long long) pow(10, mult - 1) + ((n - 1) / mult));
            cout << number[(n - 1) % mult] << endl;
            break;
        }
    }
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
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}