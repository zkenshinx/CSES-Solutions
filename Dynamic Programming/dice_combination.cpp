#include <bits/stdc++.h>

using namespace std;

#define DICE_FACES 6
const int mod = 1e9 + 7;

void solve(int n) {
    /* dp[S] -> the number of ways to construct sum S*/
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= DICE_FACES; ++j) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n] << endl;
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