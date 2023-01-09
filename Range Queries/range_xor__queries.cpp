#include <bits/stdc++.h>
/* Time Complexity: O(n + q) */
/* Memory Complexity: O(n) */
using namespace std;

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /* Input */
    int n, q;
    cin >> n >> q;
    vector<int> prefix_xor(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v; 
        cin >> v;
        prefix_xor[i] = prefix_xor[i - 1] ^ v;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (prefix_xor[b] ^ prefix_xor[a - 1]) << endl;
    }
    return 0;
}