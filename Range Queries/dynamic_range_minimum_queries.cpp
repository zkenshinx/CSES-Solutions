#include <bits/stdc++.h>
/* Time Complexity: O(n + qlogn) */
/* Memory Complexity: O(n) */
using namespace std;

#define MAXN 200005

int tree[4 * MAXN];
int arr[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
    } else {
        int m = (l + r) / 2;
        build(2 * node + 1, l, m);
        build(2 * node + 2, m + 1, r);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void update(int node, int l, int r, int index, int value) {
    if (l == r) {
        tree[node] = value;
    } else {
        int m = (l + r) / 2;
        if (index <= m) {
            update(2 * node + 1, l, m, index, value);
        } else {
            update(2 * node + 2, m + 1, r, index, value);
        }
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

int query(int node, int l, int r, int start, int end) {
    if (end < l || r < start) {
        return INT32_MAX;
    } else if (start <= l && r <= end) {
        return tree[node];
    } else {
        int m = (l + r) / 2;
        return min(query(2 * node + 1, l, m, start, end), query(2 * node + 2, m + 1, r, start, end));
    }
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /* Input */
    int n, q;
    cin >> n >> q;
    arr[0] = INT32_MAX;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    build(0, 0, n);

    /* Solution Using Segment Tree */
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(0, 0, n, k, u);
            arr[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(0, 0, n, a, b) << endl;
        }
    }
    return 0;
}