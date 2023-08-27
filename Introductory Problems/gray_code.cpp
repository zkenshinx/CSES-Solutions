#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<string> helper(int n) {
    if (n == 1) 
        return {"0", "1"};

    vector<string> rec = helper(n - 1);

    vector<string> result;
    for (int i = 0; i < rec.size(); ++i)
        result.push_back("0" + rec[i]);
    for (int i = rec.size() - 1; i >= 0; --i)
        result.push_back("1" + rec[i]);

    return result;
}

void solve(int n) {
    // 0 -> 1
    // 00 -> 01 -> 11 -> 10
    // 000 -> 001 -> 011 -> 010 -> 110 -> 111 -> 101 -> 100
    vector<string> result = helper(n);
    for (auto v : result)
        cout << v << '\n';
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n;
    cin >> n;

    solve(n);
    return 0;
}