#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int n) {
    int l = 0;
    set<int> st;
    int result = 0;
    for (int r = 0; r < n; ++r) {
        int curr = arr[r];
        if (st.count(curr)) {
            while (arr[l] != curr) {
                st.erase(arr[l]);
                ++l;
            }
            ++l;
        } else {
            result = max(result, r - l + 1);
            st.insert(arr[r]);
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
    vector<int> arr(n);
    for (auto& v : arr)
        cin >> v;
    
    solve(arr, n);
    return 0;
}