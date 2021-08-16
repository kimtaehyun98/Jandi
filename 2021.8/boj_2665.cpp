#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int n, arr[55][55], dis[55][55];
bool check[55][55];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct point {
	int x;
	int y;
	int w;
};

struct cmp {
	bool operator() (point a, point b) {
		return a.w > b.w;
	}
};

void dijkstra() {
	priority_queue<point, vector<point>, cmp> pq;
	pq.push(point{ 0,0,0 });
	dis[0][0] = 0;
	while (!pq.empty()) {
		point t = pq.top();
		pq.pop();
		int x = t.x, y = t.y;
		if (check[x][y]) continue;
		check[x][y] = true;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && check[nx][ny] == false) {
				if (dis[x][y] + arr[nx][ny] < dis[nx][ny]) {
					dis[nx][ny] = dis[x][y] + arr[nx][ny];
					pq.push(point{ nx, ny, dis[nx][ny] });
				}
			}
		}
	}
}

void init() {
	memset(check, false, sizeof(check));
	memset(dis, 127, sizeof(dis));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
			arr[i][j] = arr[i][j] == 0 ? 1 : 0;
		}
	}
	init();
	dijkstra();
	printf("%d\n", dis[n - 1][n - 1]);
}