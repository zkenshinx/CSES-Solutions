#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& numbers, int n) {
    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<long long> prefix_sum(n);
    prefix_sum[0] = numbers[0];
    for (int i = 0; i < n; ++i) {
        if (i > 0) prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
        dp[i][i] = numbers[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            long long first = numbers[i] + prefix_sum[j] - prefix_sum[i] - dp[i + 1][j];
            long long second = numbers[j] + prefix_sum[j - 1] - (i == 0 ? 0 : prefix_sum[i - 1]) - dp[i][j - 1];
            dp[i][j] = max(first, second);
        }
    }
    cout << dp[0][n - 1] << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    vector<int> numbers(n);
    for (auto& number : numbers)
        cin >> number;
    solve(numbers, n);
    return 0;
}