#include <bits/stdc++.h>
/* Time Complexity O(n * logn) */
/* Space Complexity O(1) */
using namespace std;

void solve(vector<int>& numbers, int n) {
    sort(numbers.begin(), numbers.end());
    int result = 1;
    for (int i = 1; i < n; ++i) {
        if (numbers[i] != numbers[i - 1]) {
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
    int n; 
    cin >> n;
    vector<int> numbers(n);
    for (auto& num : numbers) 
        cin >> num; 
    solve(numbers, n);
    return 0;
}