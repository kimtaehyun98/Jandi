#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii>g[5005];
bool check[5005];
int dis[5005];

void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, s));
	dis[s] = 0;
	while (!pq.empty()) {
		int wei = pq.top().first;
		int ver = pq.top().second;
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
	int V, E, P, a, b, c;
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		g[a].push_back(pii(b, c));
		g[b].push_back(pii(a, c));
	}
	// 1->P, 1->V 구하기
	init();
	dijkstra(1);
	int op = dis[P], ov = dis[V];
	// P->V 구하기
	init();
	dijkstra(P);
	int pv = dis[V];
	string ans = op + pv <= ov ? "SAVE HIM" : "GOOD BYE";
	cout << ans << "\n";
}