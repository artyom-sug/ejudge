#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};

int t;
int r, c;
char grid[1000][1000];
int dist[1000][1000];
bool vis[1000][1000];

point step[4]{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

inline bool check(int x, int y) {
	return x >= 0 and x < r and y >= 0 and y < c and grid[x][y] == '.';
}

point bfs(point st);

int main() {
	cin >> t;
	for (int test = 0; test < t; test++) {
		point st({ -1, -1 });
		bool f = 0;
		cin >> c >> r;
		for (int i = 0; i < r; i++) {
			cin >> grid[i];
			for (int j = 0; j < c and !f; j++) {
				if (grid[i][j] == '.') {
					st = point({ i, j });
					f = 1;
				}
			}
		}
		if (!f) {
			cout << "Maximum rope length is 0.\n";
			continue;
		}
		point far = bfs(st);
		point res = bfs(far);
		cout << "Maximum rope length is " << dist[res.x][res.y] << ".\n";
	}
}

point bfs(point st) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			vis[i][j] = 0;
			dist[i][j] = 0;
		}
	}
	queue<point> q;
	q.push(st);
	vis[st.x][st.y] = 1;
	point far = st;
	int mx = 0;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (dist[cur.x][cur.y] > mx) {
			mx = dist[cur.x][cur.y];
			far = cur;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + step[i].x;
			int ny = cur.y + step[i].y;
			if (check(nx, ny) and !vis[nx][ny]) {
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return far;
}
