#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n % 4 != 0 && n % 4 != 3) {
        cout << "NO\n";
        return;
    }
    vector<int> a, b;
    while (n > 3) {
        a.push_back(n);
        a.push_back(n - 3);
        b.push_back(n - 2);
        b.push_back(n - 1);
        n -= 4;
    }
    if (n == 3) {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);
    }
    cout << "YES\n";
    auto print_vec = [](vector<int>& arr) {
        cout << arr.size() << endl;
        for (auto v : arr)   
            cout << v << " ";
        cout << endl;
    };
    print_vec(a);
    print_vec(b);
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