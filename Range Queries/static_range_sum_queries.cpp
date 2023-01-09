#include <bits/stdc++.h>
/* Time Complexity: O(n + q) */
/* Memory Complexity: O(n) */
using namespace std;

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        int current;
        cin >> current;
        prefix[i] = prefix[i - 1] + current;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
    return 0;
}
