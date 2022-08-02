#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& coins, int n) {
    int sum = accumulate(coins.begin(), coins.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0)
                dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i - 1]];
        }
    }
    vector<int> result;
    for (int j = 1; j <= sum; ++j) {
        if (dp[n][j])
            result.push_back(j);
    }
    cout << result.size() << endl;
    for (auto res : result)
        cout << res << " ";
    cout << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n;
    cin >> n;
    vector<int> coins(n);
    for (auto& coin : coins)
        cin >> coin;

    solve(coins, n);
    return 0;
}