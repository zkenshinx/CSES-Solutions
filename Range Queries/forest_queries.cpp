#include <bits/stdc++.h>
/* Time Complexity: O(n^2 + q) */
/* Memory Complexity: O(n^2) */
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   int n, q;
   cin >> n >> q;
   vector<string> grid(n);
   for (auto& row : grid)
      cin >> row;
   vector<vector<int>> dp(n + 1, vector<int>(n + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (grid[i - 1][j - 1] == '*');
      }
   }
   while (q--) {
      int i1, j1, i2, j2;
      cin >> i1 >> j1 >> i2 >> j2;
      int res = dp[i2][j2] - dp[i1 - 1][j2] - dp[i2][j1 - 1] + dp[i1 - 1][j1 - 1];
      cout << res << endl;
   }
   return 0;
}