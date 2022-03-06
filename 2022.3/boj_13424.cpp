#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dis[101][101], fr[101];
bool check[101];
vector<pii>g[101];

void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	dis[s][s] = 0;
	pq.push(pii(0, s)); // 가중치, 시작점
	while (!pq.empty()) {
		int wei = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (check[cur]) continue;
		check[cur] = true;
		for (int k = 0; k < g[cur].size(); k++) {
			int next = g[cur][k].second;
			int nw = g[cur][k].first;
			if (dis[s][next] > dis[s][cur] + nw) {
				dis[s][next] = dis[s][cur] + nw;
				pq.push(pii(dis[s][next], next));
			}
		}
	}
}

int main() {
	int t, n, m, a, b, c, k;
	cin >> t;
	while (t--) {
		memset(dis, 127, sizeof(dis));
		cin >> n >> m;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			g[a].push_back(pii(c, b));
			g[b].push_back(pii(c, a));
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> fr[i];
		}
		for (int i = 1; i <= n; i++) { // 모든 방 최단거리 구하기
			memset(check, false, sizeof(check));
			dijkstra(i);
		}
		int cmp = INT_MAX, ans = 0;
		for (int i = 1; i <= n; i++) { // 모든 방을 돌면서 모든 친구들까지의 거리 구하기
			int temp = 0;
			for (int j = 0; j < k; j++) {
				temp += dis[i][fr[j]];
			}
			if (cmp > temp) {
				cmp = temp;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}