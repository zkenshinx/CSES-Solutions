#include <bits/stdc++.h>
/* Time Complexity O(n * x) where x is desired_sum */
/* Space Complexity O(x) */
#define INFINITY INT32_MAX
using namespace std;

void solve(vector<int>& coins, int n, int desired_sum) {
    /* dp[S] -> minimum numbers of coins required to get sum S.
    If impossible, then dp[S] = infinity */
    vector<int> dp(desired_sum + 1, INFINITY);
    dp[0] = 0;
    for (int i = 1; i <= desired_sum; ++i) {
        for (int coin : coins) {
            if (i - coin < 0 || dp[i - coin] == INFINITY) continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    int result = dp[desired_sum] == INFINITY ? -1 : dp[desired_sum];
    cout << result << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n, desired_sum; 
    cin >> n >> desired_sum;
    vector<int> coins(n);
    for (auto& coin : coins) 
        cin >> coin;
    solve(coins, n, desired_sum);
    return 0;
}