#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int INF = INT_MAX;
using llong = long long;

int n, m;
int a, b, d;
int adj[1001][1001];
llong dist[1001];
int dp[1001];
bool vis[1001];

void djkstra(int start);

int dfs(int u);

int main() {
	while (cin >> n and n != 0) {
		cin >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				adj[i][j] = i == j ? 0 : INF;
			}
			dp[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			adj[a][b] = d;
			adj[b][a] = d;
		}
		djkstra(2);
		cout << dfs(1) << endl;
	}
}

void djkstra(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
		vis[i] = 0;
	}
	dist[start] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] and (u == -1 or dist[j] < dist[u])) {
				u = j;
			}
		}
		if (u == -1 or dist[u] == INF) break;
		vis[u] = 1;
		for (int v = 1; v <= n; v++) {
			if (adj[u][v] != INF and !vis[v]) {
				llong ndist = dist[u] + adj[u][v];
				dist[v] = min(dist[v], ndist);
			}
		}
	}
}

int dfs(int u) {
	if (u == 2) return 1;
	if (dp[u] != -1) return dp[u];
	dp[u] = 0;
	for (int v = 1; v <= n; v++) {
		if (adj[u][v] != INF and dist[v] < dist[u]) {
			dp[u] += dfs(v);
		}
	}
	return dp[u];
}
