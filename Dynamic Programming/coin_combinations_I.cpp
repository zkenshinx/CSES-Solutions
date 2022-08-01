#include <bits/stdc++.h>
/* Time Complexity: O(n * x) */
/* Space Complexity: O(x) */
using namespace std;

const int mod = 1e9+7;
 
void solve(vector<int>& coins, int n, int x) {
    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n && i - coins[j] >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    cout << dp[x] << endl;
}
 
int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    /* Input */
    int n, x; 
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& coin : coins)
        cin >> coin;

    solve(coins, n, x);    
    return 0;
}