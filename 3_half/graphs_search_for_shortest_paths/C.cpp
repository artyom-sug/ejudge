#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int INF = INT_MAX;

int adj[101][101];
int n, e, t, m;
int x, y;

int main() {
	cin >> n >> e >> t >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adj[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cin >> adj[x][y];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] < INF and adj[k][j] < INF) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i][e] <= t) cnt++;
	}
	cout << cnt << endl;
}
