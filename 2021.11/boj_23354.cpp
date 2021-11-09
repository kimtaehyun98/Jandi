#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

int n, sx, sy, ans = INT_MAX;
int arr[1004][1004];
int dis[1004][1004];
bool check[1004][1004];
bool btch[10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pii>sol;
vector<int>temp[7];

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

void dijkstra(int x, int y) {
	priority_queue<node, vector<node>, cmp>pq;
	pq.push(node{ 0,x,y });
	dis[x][y] = 0;
	while (!pq.empty()) {
		int wei = pq.top().w;
		x = pq.top().x;
		y = pq.top().y;
		pq.pop();
		if (check[x][y]) continue;
		check[x][y] = true;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
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
}

void bt(int cnt, int stop, int cmp, int s) {
	if (cnt == stop) {
		cmp += temp[s][0];
		ans = min(cmp, ans);
		return;
	}
	for (int i = 0; i < temp[s].size(); i++) {
		if (s == i || i == 0) continue;
		if (btch[i] == false) {
			cmp += temp[s][i];
			btch[i] = true;
			bt(cnt + 1, stop, cmp, i);
			btch[i] = false;
			cmp -= temp[s][i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				sx = i; sy = j;
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 0) {
				sol.push_back(pii(i, j));
			}
		}
	}
	init();
	dijkstra(sx, sy);
	temp[0].push_back(0);
	for (int i = 0; i < sol.size(); i++) {
		temp[0].push_back(dis[sol[i].first][sol[i].second]);
	}
	for (int i = 1; i <= sol.size(); i++) {
		init();
		dijkstra(sol[i - 1].first, sol[i - 1].second);
		temp[i].push_back(temp[0][i]);
		for (int k = 0; k < sol.size(); k++) {
			if (i - 1 == k) temp[i].push_back(0);
			else temp[i].push_back(dis[sol[k].first][sol[k].second]);
		}
	}
	// 백트래킹
	memset(btch, false, sizeof(btch));
	bt(0, sol.size(), 0, 0);
	cout << ans << "\n";
}