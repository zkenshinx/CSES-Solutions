#include <bits/stdc++.h>

using namespace std;

void solve(long long n) {
    while (n != 1) {
        cout << n << " ";
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
    }
    cout << "1\n";
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    long long n;
    cin >> n;
    
    solve(n);
    return 0;
}
