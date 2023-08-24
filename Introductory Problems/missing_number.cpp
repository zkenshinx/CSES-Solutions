#include <bits/stdc++.h>
 
using namespace std;
 
void solve(vector<int>& arr) {
    long long sum = 0;
    for (auto v : arr)
        sum += v;
    int result = (long long) (arr.size() + 2) * (arr.size() + 1) / 2 - sum;
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
    vector<int> arr(n - 1);
    for (auto& v : arr)
        cin >> v;
    
    solve(arr);
    return 0;
}