#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<int, int>>& arr, int n) {
    vector<pair<int, int>> order;
    for (int i = 0; i < n; ++i) {
        order.push_back({arr[i].first, 1});
        order.push_back({arr[i].second, -1});
    }
    sort(order.begin(), order.end());
    int result = 0, current = 0;
    for (auto [a, b] : order) {
        current += b;
        result = max(result, current);
    }
    cout << result << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto& [a, b] : arr)
        cin >> a >> b;

    solve(arr, n);
    return 0;
}