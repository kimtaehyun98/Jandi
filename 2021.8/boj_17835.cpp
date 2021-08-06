#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int n, m, k, u, v, x;
bool check[100007], meet[100007];
vector<pil>g[100007];
ll dis[100007];

void dijkstra(vector<int>pl) {
	memset(dis, 127, sizeof(dis));
	memset(check, false, sizeof(check));
	priority_queue<pli, vector<pli>, greater<pli> >pq;
	for (int i = 0; i < pl.size(); i++) {
		pq.push(make_pair(0, pl[i]));
		dis[pl[i]] = 0;
	}
	while (!pq.empty()) {
		int ver = pq.top().second;
		ll wei = pq.top().first;
		pq.pop();
		if (check[ver] == true)continue;
		check[ver] = true;
		if (dis[ver] != wei)continue;
		for (int i = 0; i < g[ver].size(); i++) {
			ll a = g[ver][i].second;
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
	cin >> n >> m >> k;
	ll w;
	for (int i = 0; i < m; i++) { // 이 문제의 핵심! 단방향 간선이기 때문에 간선을 뒤집어주기!
		cin >> u >> v >> w;
		g[v].push_back(pil(u, w)); 
	}
	memset(meet, true, sizeof(meet));
	vector<int>temp;
	for (int i = 0; i < k; i++) {
		cin >> x; meet[x] = false; temp.push_back(x);
	}
	dijkstra(temp);
	pil ans = pil(0, 0);
	for (int i = 1; i <= n; i++) if (meet[i] && dis[i] > ans.second) ans = pil(i, dis[i]);
	cout << ans.first << "\n" << ans.second << "\n";
}