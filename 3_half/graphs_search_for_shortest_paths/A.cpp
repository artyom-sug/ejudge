#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define all(v) v.begin(), v.end()
#define pf first
#define ps second

const int INF = INT_MAX;

int n, m;
int a, b, c;
int k;

bool compare(pair<int, int>& a, pair<int, int> b);

int main() {
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}

		int adj[200][200];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = INF;
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			adj[a][b] = c;
			adj[b][a] = c;
		}
		cin >> k;
		vector<int> dist(n, INF);
		vector<bool> visit(n, 0);
		dist[0] = 0;
		for (int i = 0; i < n; i++) {
			int v = -1;
			for (int j = 0; j < n; j++) {
				if (!visit[j] and (v == -1 or dist[j] < dist[v])) {
					v = j;
				}
			}
			if (dist[v] == INF) break;
			visit[v] = 1;
			for (int u = 0; u < n; u++) {
				if (adj[v][u] != INF and dist[v] + adj[v][u] < dist[u]) {
					dist[u] = dist[v] + adj[v][u];
				}
			}
		}
		vector<pair<int, int>> citi;
		for (int i = 1; i < n; i++) {
			citi.push_back({ dist[i], i });
		}
		sort(all(citi), compare);
		cout << citi[k - 1].ps << endl;
	}
}

bool compare(pair<int, int>& a, pair<int, int> b) {
	if (a.pf != b.pf) {
		return a.pf < b.pf;
	}
	return a.ps < b.ps;
}
