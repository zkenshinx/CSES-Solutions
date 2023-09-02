#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(vector<int>& arr, int n) {
    long long result = INT64_MIN;
    long long current = 0;
    for (int i = 0; i < n; ++i) {
        current += arr[i];
        result = max(result, current);
        if (current < 0)
            current = 0;
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
    vector<int> arr(n);
    for (auto& v : arr)
        cin >> v;
    
    solve(arr, n);
    return 0;
}