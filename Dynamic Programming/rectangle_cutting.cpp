#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b) {
    /* dp[i][j] -> Number of cuts needed for rectangle having dimensions (i, j) */
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) continue;
            dp[i][j] = 1e9;
            /* Horizontal Cut */
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            /* Vertical Cut */
            for (int k = 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int a, b;
    cin >> a >> b;

    solve(a, b);    

    return 0;
}