#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, r, a, b, w, ans = 0;
int item[33], dis[101][101];
bool check[101];
vector<pii>g[101];

void dijkstra(int x) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[x][x] = 0;
	pq.push(pii(0, x));
	while (!pq.empty()) {
		int wei = pq.top().first;
		int ver = pq.top().second;
		pq.pop();
		if (check[ver]) continue;
		check[ver] = true;
		for (int k = 0; k < g[ver].size(); k++) {
			int next = g[ver][k].first;
			int w = g[ver][k].second;
			if (dis[x][next] > dis[x][ver] + w) {
				dis[x][next] = dis[x][ver] + w;
				pq.push(pii(dis[x][next], next));
			}
		}
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> w;
		g[a].push_back(pii(b, w));
		g[b].push_back(pii(a, w));
	}
	memset(dis, 127, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		dijkstra(i);
	}
	for (int i = 1; i <= n; i++) {
		int temp = item[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dis[i][j] <= m) temp += item[j];
		}
		ans = max(ans, temp);
	}
	cout << ans << "\n";
}