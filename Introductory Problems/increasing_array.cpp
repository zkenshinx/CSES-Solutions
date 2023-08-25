#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int n) {
	long long result = 0;
	for (int i = 1; i < n; ++i) {
		result += max(arr[i - 1] - arr[i], 0);
		arr[i] = max(arr[i - 1], arr[i]);
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
