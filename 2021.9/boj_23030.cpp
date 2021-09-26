#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, a, b, c, d, t;
vector<pii>g[505];
int dis[505];
bool check[505];
bool trans[505][505];

// X번 노선의 Y번째 역 = 50*(X-1) + Y 노드로 표현
int changeNode(int x, int y) {
	return 50 * (x - 1) + y;
}

void dijkstra(int x) {
	dis[x] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		int now = pq.top().second;
		int wei = pq.top().first;
		pq.pop();
		if (check[now] == true)continue;
		check[now] = true;
		if (dis[now] < wei) continue;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].first;
			int ww = g[now][i].second;
			if (trans[now][next]) ww = t;
			if (dis[now] + ww < dis[next]) {
				dis[next] = dis[now] + ww;
				pq.push(make_pair(dis[next], next));
			}
		}
	}
}

void init() {
	memset(dis, 127, sizeof(dis));
	memset(check, false, sizeof(check));
}

int main() {
	cin >> n;
	vector<int>station(n);
	for (int i = 0; i < n; i++) cin >> station[i];
	// 각 역에 index를 붙여주어 노드화 시킴
	for (int i = 0; i < station.size(); i++) {
		int prev = 0;
		for (int k = 1; k <= station[i]; k++) {
			int now = changeNode(i + 1, k);
			if (k != 1) {
				g[now].push_back(pii(prev, 1));
				g[prev].push_back(pii(now, 1));
			}
			prev = now;
		}
	}
	cin >> m;
	memset(trans, false, sizeof(trans));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		int x = changeNode(a, b), y = changeNode(c, d);
		g[x].push_back(pii(y, 1));  g[y].push_back(pii(x, 1));
		trans[x][y] = true; trans[y][x] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		init();
		cin >> t >> a >> b >> c >> d;
		int start = changeNode(a, b);
		int end = changeNode(c, d);
		dijkstra(start);
		cout << dis[end] << "\n";
	}
}