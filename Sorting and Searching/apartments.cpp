#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int result = 0;
    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
        while (j < b.size() && b[j] < a[i] - k) 
            ++j;
        if (j == b.size())
            break;
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            ++j;
            ++result;
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& v: a)
        cin >> v;
    for (auto& v : b)
        cin >> v;
    
    solve(a, b, k);
    return 0;
}