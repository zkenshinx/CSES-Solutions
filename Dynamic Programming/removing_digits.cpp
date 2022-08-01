#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto c : to_string(i)) {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << endl;
}
 
int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /* Input */
    int n; 
    cin >> n;

    solve(n);    
    return 0;
}