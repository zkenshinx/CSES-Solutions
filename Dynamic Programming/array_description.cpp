#include <bits/stdc++.h>
/* Time Complexity: O(n * m) */
/* Memory Complexity: O(n * m) -> can be optimized to O(n) */
using namespace std;

const int mod = 1e9 + 7;

void solve(vector<int>& arr, int n, int m) {
   /* dp[i][j] -> number of ways such that i-th element is j so far */
   vector<vector<int>> dp(n, vector<int>(m + 1));
   if (arr[0] == 0) {
      fill(dp[0].begin() + 1, dp[0].end(), 1);
   } else {
      dp[0][arr[0]] = 1;
   }
   for (int i = 1; i < n; ++i) {
      auto calc_dp = [&](int v) {
         long long curr = 0;
         if (v >= 2) curr += dp[i - 1][v - 1];
         curr += dp[i - 1][v];
         if (v < m) curr += dp[i - 1][v + 1];
         dp[i][v] = curr % mod;
      };
      if (arr[i] == 0) {
         for (int j = 1; j <= m; ++j) {
            calc_dp(j);
         }
      } else {
         calc_dp(arr[i]);
      }
   }
   int res = accumulate(dp.back().begin(), dp.back().end(), 0LL) % mod;
   cout << res << endl;
}

int main() {
   /* Faster Input/Output */
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   /* Input */
   int n, m;
   cin >> n >> m;
   vector<int> arr(n);
   for (auto& v : arr)
      cin >> v;

   solve(arr, n, m);
      
   return 0;
}
