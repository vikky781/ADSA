#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void bfs(int start, vector<vector<int>> adj) {
  int n = adj.size();
  vector<bool> vis(n, false);
  queue<int> q;
  vis[start] = true;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (int neighbor : adj[node]) {
      if (!vis[neighbor]) {
        vis[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs(0, adj);
  return 0;
}