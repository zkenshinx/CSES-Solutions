#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(vector<int>& arr, int x) {
    map<int, int> mp;
    for (int i = 0; i < arr.size(); ++i) {
        if (mp.count(x - arr[i])) {
            cout << mp[x - arr[i]] << " " << i + 1 << '\n';
            return;
        }
        mp[arr[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto& v : arr)
        cin >> v;
    
    solve(arr, x);
    return 0;
}