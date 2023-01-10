#include <bits/stdc++.h>
/* Time Complexity: O(n + m * logn) */
/* Memory Complexity: O(n) */
using namespace std;

#define MAXN 200005

int tree[4 * MAXN];

void build(vector<int>& arr, int node, int l, int r) {
   if (l == r) {
      tree[node] = arr[l];
   } else {
      int m = (l + r) / 2;
      build(arr, 2 * node + 1, l, m);
      build(arr, 2 * node + 2, m + 1, r);
      tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
   }
}

int query_update(int node, int l, int r, int num) {
   if (tree[node] < num) return 0;
   if (l == r) {
      tree[node] -= num;
      return l + 1;
   } else {
      int m = (l + r) / 2;
      int res;
      if (tree[2 * node + 1] >= num) {
         res = query_update(2 * node + 1, l, m, num);
      } else {
         res = query_update(2 * node + 2, m + 1, r, num);
      }
      tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
      return res;
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   int n, m;
   cin >> n >> m;
   vector<int> h(n);
   for (auto& v : h)
      cin >> v;
   build(h, 0, 0, n - 1);
   for (int i = 0; i < m; ++i) {
      int r; cin >> r;
      cout << query_update(0, 0, n - 1, r) << " ";
   }
   cout << endl;
   return 0;
}