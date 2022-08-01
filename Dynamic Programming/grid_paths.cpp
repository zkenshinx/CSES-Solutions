#include <bits/stdc++.h>
/* Time Complexity O(n^2) */
/* Space Complexity O(n^2) */
using namespace std;

const int mod = 1e9 + 7;

void solve(vector<string>& grid, int n) {
    /* dp[i][j] -> number of ways to get from (0, 0) to (i ,j) */
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') continue;
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    solve(grid, n);
    return 0;
}