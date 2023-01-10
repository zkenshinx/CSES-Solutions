#include <bits/stdc++.h>
/* Time Complexity: O(n * logn) */
/* Memory Complexity: O(n) */
using namespace std;

#define MAXN 200005

int tree[4 * MAXN];

void build(int node, int l, int r) {
   if (l == r) {
      tree[node] = 1;
   } else {
      int m = (l + r) / 2;
      build(2 * node + 1, l, m);
      build(2 * node + 2, m + 1, r);
      tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
   }
}

int query(int node, int l, int r, int num) {
   if (l == r) {
      tree[node] = 0;
      return l;
   } else {
      int m = (l + r) / 2;
      int res;
      if (tree[2 * node + 1] >= num) {
         res = query(2 * node + 1, l, m, num);
      } else {
         res = query(2 * node + 2, m + 1, r, num - tree[2 * node + 1]);
      }
      tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
      return res;
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   int n; cin >> n;
   vector<int> arr(n);
   for (auto& v : arr)
      cin >> v;
   build(0, 0, n - 1);
   for (int i = 0; i < n; ++i) {
      int v; cin >> v;
      cout << arr[query(0, 0, n - 1, v)] << " ";
   }
   cout << endl;
   return 0;
}