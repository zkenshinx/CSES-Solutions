#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, long long x) {
    map<long long, int> mp;
    mp[0LL] = 1;
    long long pre = 0;
    long long result = 0;
    for (auto v : arr) {
        pre += v;
        result += mp[pre - x];
        mp[pre]++;
    }
    cout << result << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n; long long x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto& v : arr)
        cin >> v;
    
    solve(arr, x);
    return 0;
}