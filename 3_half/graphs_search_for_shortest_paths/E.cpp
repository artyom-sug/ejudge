#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;
#define pb push_back
using llong = long long;
//#define int long long

const int INF = INT_MAX;

struct point {
	int x, y;
};

int x, y;
string grid[20];
vector<point> points;
int n;
int dist[16][16];


point step[8]{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int bfs(point& start, point& end);

int tsp(int mask, int pos, vector<vector<llong>>& dp);

int main() {
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> grid[i];
		for (int j = 0; j < y; j++) {
			if (grid[i][j] != '.') {
				points.pb({ i, j });
			}
		}
	}
	n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dist[i][j] = bfs(points[i], points[j]);
			dist[j][i] = dist[i][j];
		}
	}
	vector<vector<llong>> dp(1 << n, vector<llong>(n, INF));
	int res = tsp(1 << 0, 0, dp);
	cout << res << endl;
}

inline bool check(int x, int y) {
	return x >= 0 and x < ::x and y >= 0 and y < ::y;
}

int bfs(point& start, point& end) {
	vector<vector<bool>> vis(x, vector<bool>(y, 0));
	vector<vector<int>> dist(x, vector<int>(y, INF));
	queue<point> q;
	q.push(start);
	vis[start.x][start.y] = 1;
	dist[start.x][start.y] = 0;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.x == end.x and cur.y == end.y) {
			return dist[end.x][end.y];
		}
		for (auto st : step) {
			int nx = cur.x + st.x;
			int ny = cur.y + st.y;
			if (check(nx, ny) and !vis[nx][ny]) {
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return INF;
}

int tsp(int mask, int pos, vector<vector<llong>>& dp) {
	if (mask == (1 << n) - 1) {
		return dist[pos][0];
	}
	if (dp[mask][pos] != INF) {
		return dp[mask][pos];
	}
	int res = INF;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			int nmask = mask | (1 << i);
			int nc = dist[pos][i] + tsp(nmask, i, dp);
			res = res < nc ? res : nc;
		}
	}
	dp[mask][pos] = res;
	return res;
}
