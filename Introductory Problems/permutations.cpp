#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    cout << endl;
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
