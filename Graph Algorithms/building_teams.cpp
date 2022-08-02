#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& color, int v, int cl = 1) {
    color[v] = cl;
    for (auto to : graph[v]) {
        if (color[to] == 0) {
            bool currflag = dfs(graph, color, to, cl == 1 ? 2 : 1);
            if (!currflag) return false;
        } else if (color[to] == cl) {
            return false;
        }
    }
    return true;
}

void solve(vector<vector<int>>& graph, int n) {
    vector<int> color(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            bool res = dfs(graph, color, i);
            if (!res) {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << ' ';
    }
    cout << endl;
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);  
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(graph, n);
    return 0;
}