#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<int, int>>& arr, int n) {
    sort(arr.begin(), arr.end(), [&](auto a, auto b) {
        return a.second < b.second;
    });
    int result = 0;
    int current = -1;
    for (auto [a, b] : arr) {
        if (current <= a) {
            result++;
            current = b;
        }
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