#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<pair<int, int>> result;

void move_disk(int from, int to) {
    result.push_back({from, to});
}

int get_free_stack(int a, int b) {
    return 6 - a - b;
}

void move_stack(int n, int from, int to) {
    if (n == 1) {
        move_disk(from, to);
    } else {
        move_stack(n - 1, from, get_free_stack(from, to));
        move_disk(from, to);
        move_stack(n - 1, get_free_stack(from, to), to);
    }
}

void helper(int n, int stack_index) {
    if (n == 1) {
        move_disk(stack_index, 3);
    } else if (stack_index == 1) {
        move_stack(n - 1, 1, 2);
        move_disk(1, 3);
        helper(n - 1, 2);
    } else if (stack_index == 2) {
        move_stack(n - 1, 2, 1);
        move_disk(2, 3);
        helper(n - 1, 1);
    }
}

void solve(int n) {
    helper(n, 1);
    cout << result.size() << endl;
    for (auto [a, b] : result) 
        cout << a << " " << b << '\n';
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