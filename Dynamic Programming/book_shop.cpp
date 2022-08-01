#include <bits/stdc++.h>
/* Time Complexity: O(n * x) */
/* Space Complexity: O(n * x) */
using namespace std;

void solve(vector<int>& price, vector<int>& pages, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - price[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
        }
    }
    int result = 0;
    for (int j = 0; j <= x; ++j) result = max(result, dp[n][j]);
    cout << result << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (auto& price : prices) cin >> price;
    for (auto& page : pages) cin >> page;

    solve(prices, pages, n, x);
    return 0;
}