#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<int>g[100001];
bool check[100001];
int land[100001];

void bfs(int x, int s) {
	queue<int>q;
	q.push(x);
	check[x] = true;
	land[x] = s;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int k = 0; k < g[x].size(); k++) {
			int nx = g[x][k];
			if (!check[nx]) {
				check[nx] = true;
				land[nx] = s;
				q.push(nx);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// ¼¶ ±¸ÇÏ±â
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			bfs(i, cnt++);
		}
	}
	int prev = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (i == 0) prev = land[c];
		else {
			if (prev != land[c]) ans++;
			prev = land[c];
		}
	}
	cout << ans << "\n";
}