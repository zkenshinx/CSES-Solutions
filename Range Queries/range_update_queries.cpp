#include <bits/stdc++.h>
using namespace std;
/* Time Complexity: O(n + q * logn) */
/* Memory Complexity: O(n) */
#define MAXN 200500

long long tree[4 * MAXN];

void update(int node, int l, int r, int index, long long value) {
    if (l == r) {
        tree[node] += value;
    } else {
        int m = (l + r) / 2;
        if (index <= m) {
            update(2 * node + 1, l, m, index, value);
        } else {
            update(2 * node + 2, m + 1, r, index, value);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

long long query(int node, int l, int r, int start, int end) {
    if (end < l || r < start) {
        return 0;
    } else if (start <= l && r <= end) {
        return tree[node];
    } else {
        int m = (l + r) / 2;
        return query(2 * node + 1, l, m, start, end) + query(2 * node + 2, m + 1, r, start, end);
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   int n, q;
   cin >> n >> q;
   vector<long long> arr(n);
   for (auto& v : arr) 
      cin >> v;
   while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
         int a, b, u; 
         cin >> a >> b >> u;
         --a; --b;
         update(0, 0, n, a, u);
         update(0, 0, n, b + 1, -u);
      } else {
         int k;
         cin >> k;
         --k;
         cout << arr[k] + query(0, 0, n, 0, k) << endl;
      }
   }
   return 0;
}