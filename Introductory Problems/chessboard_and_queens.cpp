#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

bool canPlace(vector<string>& grid, int i, int j) {
    if (grid[i][j] == '*')
        return false;
    for (int a = 0; a < 8; ++a) {
        if (grid[i][a] == 'q')
            return false;
        if (grid[a][j] == 'q')
            return false;
    }
    int ti = i;
    int tj = j;
    while (ti >= 0 && tj >= 0) {
        if (grid[ti][tj] == 'q')
            return false;
        --ti;
        --tj;
    }
    ti = i;
    tj = j;
    while (ti >= 0 && tj < 8) {
        if (grid[ti][tj] == 'q')
            return false;
        --ti;
        ++tj;
    }
    return true;
}

int helper(vector<string>& grid, int row) {
    if (row == 8)
        return 1;
    int result = 0;
    for (int j = 0; j < 8; ++j) {
        if (canPlace(grid, row, j)) {
            grid[row][j] = 'q';
            result += helper(grid, row + 1);
            grid[row][j] = '.';
        }
    }
    return result;
}

void solve(vector<string>& grid) {
    cout << helper(grid, 0) << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    vector<string> grid(8);
    for (auto& row : grid)
        cin >> row;

    solve(grid);
    return 0;
}