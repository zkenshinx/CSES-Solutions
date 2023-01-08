#include <bits/stdc++.h>
/* Time Complexity: O(n^3) */
/* Memory Complexity: O(n^3) */
using namespace std;

const int mod = 1e9 + 7;

int inverse(int v) {
    // Binary Exponentiaton
    function<long long(int, int)> binpow = [&](int v, int pow) {
        if (pow == 0)
            return 1LL;
        long long half = binpow(v, pow / 2);
        long long result = (half * half) % mod;
        if (pow % 2 == 1) result = result * v % mod;
        return result;
    };
    return binpow(v, mod - 2);
}

void solve(int n) {
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return;
    }
    int half = sum / 2;
    /* Knapsack problem -> finding how many sets have sum ${half} */
    vector<vector<int>> dp(n + 1, vector<int>(half + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= half; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0)
                dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= mod;
        }
    }
    cout << (1LL * dp[n][half] * inverse(2)) % mod << endl;
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
