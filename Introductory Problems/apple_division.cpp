#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(vector<int>& weights, int n) {
    long long result = INT64_MAX;
    for (int i = 0; i < (1 << n); ++i) {
        long long current_result = 0;
        for (int j = 0; j < n; ++j) 
            current_result += (i & (1 << j)) ? weights[j] : -weights[j];
        result = min(result, abs(current_result));
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
    vector<int> weights(n);
    for (auto& v : weights)
        cin >> v;

    solve(weights, n);
    return 0;
}