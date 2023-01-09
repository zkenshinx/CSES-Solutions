#include <bits/stdc++.h>
/* Time Complexity: O(nlogn+ qlogn) */
/* Memory Complexity: O(n) */
using namespace std;

struct FenwickTree {
    vector<long long> bit; 
    int n;
 
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, long long delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /* Input */
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    /* Solution Using Fenwick Tree */
    FenwickTree fen(arr);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            fen.add(k, u - arr[k]);
            arr[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            cout << fen.sum(a, b) << endl;
        }
    }
    return 0;
}