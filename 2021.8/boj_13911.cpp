#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, u, v, w, x, y;
bool check[10007], house[10007];
vector<pair<int, int>>g[10007];
int dis[10007], ans[10007][2];
vector<int>mac, star;

void dijkstra(vector<int>pl) {
	memset(dis, 127, sizeof(dis));
	memset(check, false, sizeof(check));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	for (int i = 0; i < pl.size(); i++) {
		pq.push(make_pair(0, pl[i]));
		dis[pl[i]] = 0;
	}
	while (!pq.empty()) {
		int ver = pq.top().second;
		int wei = pq.top().first;
		pq.pop();
		if (check[ver] == true)continue;
		check[ver] = true;
		if (dis[ver] != wei)continue;
		for (int i = 0; i < g[ver].size(); i++) {
			int a = g[ver][i].second;
			int b = g[ver][i].first;
			if (dis[ver] + a < dis[b]) {
				dis[b] = dis[ver] + a;
				pq.push(make_pair(dis[b], b));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back(pii(v, w));
		g[v].push_back(pii(u, w));
	}
	memset(house, true, sizeof(house));
	cin >> k >> x;
	for (int i = 0; i < k; i++) {
		cin >> v; mac.push_back(v); house[v] = false;
	}
	cin >> k >> y;
	for (int i = 0; i < k; i++) {
		cin >> v; star.push_back(v); house[v] = false;
	}
	// 맥세권인지 구하기
	dijkstra(mac);
	for (int i = 1; i <= n; i++) ans[i][0] = dis[i];
	// 스세권인지 구하기
	dijkstra(star);
	for (int i = 1; i <= n; i++) ans[i][1] = dis[i];
	int Answer = INT_MAX;
	for (int i = 1; i <= n; i++) if (ans[i][0] <= x && ans[i][1] <= y && house[i]) Answer = min(Answer, ans[i][0] + ans[i][1]);
	if (Answer == INT_MAX) cout << -1 << "\n";
	else cout << Answer << "\n";
}