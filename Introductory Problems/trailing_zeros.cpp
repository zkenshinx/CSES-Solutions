#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(int n) {
    long long result = 0;
    long long pow_five = 5;
    while (pow_five <= n) {
        result += n / pow_five;
        pow_five *= 5;
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