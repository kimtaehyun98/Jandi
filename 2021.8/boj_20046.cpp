#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int m, n;
int arr[1004][1004], dis[1004][1004];
bool check[1004][1004];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct node {
	int w;
	int x;
	int y;
};

struct cmp {
	bool operator()(node a, node b) {
		return a.w > b.w;
	}
};

void dijkstra() {
	priority_queue<node, vector<node>, cmp>pq;
	pq.push(node{ 0,0,0 });
	if (arr[0][0] == -1) return;
	dis[0][0] = arr[0][0];
	while (!pq.empty()) {
		int wei = pq.top().w;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		if (check[x][y]) continue;
		check[x][y] = true;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && arr[nx][ny] != -1) {
				if (dis[x][y] + arr[nx][ny] < dis[nx][ny]) {
					dis[nx][ny] = dis[x][y] + arr[nx][ny];
					pq.push(node{ dis[nx][ny], nx, ny });
				}
			}
		}
	}
}

void init() {
	memset(dis, 127, sizeof(dis));
	memset(check, false, sizeof(check));
	memset(arr, 0, sizeof(arr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> m >> n;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	dijkstra();
	if (check[m - 1][n - 1]) cout << dis[m - 1][n - 1] << "\n";
	else cout << -1 << "\n";
}