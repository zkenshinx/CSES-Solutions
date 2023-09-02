#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, long long x) {
    set<long long> st;
    st.insert(0LL);
    long long pre = 0;
    int result = 0;
    for (auto v : arr) {
        pre += v;
        result += st.count(pre - x);
        st.insert(pre);
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