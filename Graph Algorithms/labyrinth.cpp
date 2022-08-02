#include <bits/stdc++.h>

using namespace std;

const int diri[4] = {1, -1, 0, 0};
const int dirj[4] = {0, 0, 1, -1};
const string dirs = "UDLR";

void solve(vector<string>& grid, int n, int m) {
    int start_i, start_j, end_i, end_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start_i = i;
                start_j = j;
            } else if (grid[i][j] == 'B') {
                end_i = i;
                end_j = j;
            }
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    dp[start_i][start_j] = 0;
    while (!q.empty()) {
        auto [curr_i, curr_j] = q.front();
        q.pop();
        if (curr_i == end_i && curr_j == end_j) break;
        for (int a = 0; a < 4; ++a) {
            int next_i = curr_i + diri[a];
            int next_j = curr_j + dirj[a];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
            if (grid[next_i][next_j] == '#' || dp[next_i][next_j] != -1) continue;
            dp[next_i][next_j] = dp[curr_i][curr_j] + 1;
            q.push({next_i, next_j});
        }
    }
    if (dp[end_i][end_j] == -1) {
        cout << "NO" << endl;
        return;
    }
    int curr_i = end_i;
    int curr_j = end_j;
    string path = "";
    while (curr_i != start_i || curr_j != start_j) {
        for (int a = 0; a < 4; ++a) {
            int next_i = curr_i + diri[a];
            int next_j = curr_j + dirj[a];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
            if (dp[next_i][next_j] + 1 == dp[curr_i][curr_j]) {
                curr_i = next_i;
                curr_j = next_j;
                path += dirs[a];
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    solve(grid, n, m);
    return 0;
}