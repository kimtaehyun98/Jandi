#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii>g[50005];
bool check[50005];
int dis[50005];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 1));
	dis[1] = 0;
	while (!pq.empty()) {
		int ver = pq.top().second;
		int wei = pq.top().first;
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

int main() {
	int n, m, a, b, w;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		g[a].push_back(pii(b, w));
		g[b].push_back(pii(a, w));
	}
	memset(check, false, sizeof(check));
	memset(dis, 127, sizeof(dis));
	dijkstra();
	cout << dis[n] << "\n";
}