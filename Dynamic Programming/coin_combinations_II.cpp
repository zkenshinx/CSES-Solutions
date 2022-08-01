#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(vector<int>& coins, int n, int x) {
    /* dp[i][j] -> number of ways to get j sum using the first i coins */
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0) 
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % mod;
        }
    }
    cout << dp[n][x] << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& coin : coins)
        cin >> coin;

    solve(coins, n, x);
    return 0;
}