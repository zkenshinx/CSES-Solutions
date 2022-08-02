#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1);
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true; 
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto to : graph[curr]) {
                    if (!visited[to]) {
                        visited[to] = true;
                        q.push(to);
                    }
                }
            }
            if (i != 1) result.push_back(i);
        }
    }
    cout << result.size() << endl;
    for (auto to : result)
        cout << 1 << " " << to << endl;
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
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    solve(graph, n);
    return 0;
}