#include <bits/stdc++.h>
/* Time Complexity: O(n + m) */
/* Space Complexity: O(n + m) */
using namespace std;

void solve(vector<vector<int>>& graph, int n) {
    vector<int> parent(n + 1);
    vector<bool> visited(n + 1);

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto to : graph[curr]) {
            if (!visited[to]) {
                parent[to] = curr;
                visited[to] = true;
                q.push(to);
            }
        }
    }
    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    for (int i = n; i != 1; i = parent[i]) 
        path.push_back(i);
    path.push_back(1);
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
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