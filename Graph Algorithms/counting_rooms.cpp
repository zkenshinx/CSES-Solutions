#include <bits/stdc++.h>

using namespace std;

const int directions_i[] = {1, -1, 0, 0};
const int directions_j[] = {0, 0, 1, -1};

void dfs(vector<string>& graph, int i, int j) {
    graph[i][j] = '#';
    for (int dir = 0; dir < 4; ++dir) {
        int next_i = i + directions_i[dir];
        int next_j = j + directions_j[dir];
        if (next_i < 0 || next_i >= graph.size()) continue;
        if (next_j < 0 || next_j >= graph[0].size()) continue;
        if (graph[next_i][next_j] == '#') continue;
        dfs(graph, next_i, next_j);
    }
}

void solve(vector<string>& graph, int n, int m) {
    int room_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (graph[i][j] == '.') {
                dfs(graph, i, j);
                room_count++;
            }
        }
    }
    cout << room_count << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> graph;
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        graph.push_back(row);
    }

    solve(graph, n, m);
    return 0;
}