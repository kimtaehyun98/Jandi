#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, v, e, w;
vector<pii>g[100001];
bool check[100001];
int dis[100001], cmp[100001], arr[3];

void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, s));
	dis[s] = 0;
	while (!pq.empty()) {
		int ver = pq.top().second;
		int wei = pq.top().second;
		pq.pop();
		if (check[ver]) continue;
		check[ver] = true;
		for (int k = 0; k < g[ver].size(); k++) {
			int next = g[ver][k].first;
			int nw = g[ver][k].second;
			if (dis[next] > dis[ver] + nw) {
				dis[next] = dis[ver] + nw;
				pq.push(pii(dis[next], next));
			}
		}
	}
}

void init() {
	memset(check, false, sizeof(check));
	memset(dis, 127, sizeof(dis));
}

int main() {
	cin >> n >> arr[0] >> arr[1] >> arr[2] >> m;
	for (int i = 0; i < m; i++) {
		cin >> v >> e >> w;
		g[v].push_back(pii(e, w));
		g[e].push_back(pii(v, w));
	}
	memset(cmp, 127, sizeof(cmp));
	for (int i = 0; i < 3; i++) {
		init();
		dijkstra(arr[i]);
		for (int k = 1; k <= n; k++) {
			cmp[k] = min(cmp[k], dis[k]);
		}
	}
	int ans = 1, temp = 0;
	for (int k = 1; k <= n; k++) {
		if (temp < cmp[k]) {
			ans = k;
			temp = cmp[k];
		}
	}
	cout << ans << "\n";
}