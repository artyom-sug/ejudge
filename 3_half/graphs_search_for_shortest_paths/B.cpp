#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
const int INF = INT_MAX;

int f;
int n, m, w;
int s, e, t;

struct Edge {
	int x, y, time;
};

int main() {
	cin >> f;
	for (int ff = 0; ff < f; ff++) {
		cin >> n >> m >> w;
		vector<Edge> edge;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edge.pb({ s, e, t });
			edge.pb({ e, s, t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edge.pb({ s, e, -t });
		}
		vector<int> dist(n + 1, 0);
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			bool upd = 0;
			for (auto e : edge) {
				if (dist[e.x] > dist[e.y] + e.time) {
					dist[e.x] = dist[e.y] + e.time;
					upd = 1;
					if (i == n - 1) flag = 1;
				}
			}
			if (!upd) break;
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}
