#include <bits/stdc++.h>
/* Time Complexity: O(n * log(n) + q) */
/* Memory Complexity: O(n * log(n)) */
using namespace std;

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    int k = (int) log2(n) + 1;
    vector<vector<int>> table(k + 1, vector<int>(n));
    for (int i = 0; i < n; ++i)
        cin >> table[0][i];
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n - (1 << i) + 1; ++j) {
            table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int len = log2(b - a + 1);
        cout << min(table[len][a], table[len][b - (1 << len) + 1]) << endl;
    }
    return 0;
}
