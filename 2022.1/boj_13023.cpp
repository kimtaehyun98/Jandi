#include <bits/stdc++.h>
using namespace std;

vector<int>g[2002];
bool check[2002];
int ans = 0;

void dfs(int x, int cnt) {
	if (cnt == 4) {
		ans = 1;
		return;
	}
	for (int i = 0; i < g[x].size(); i++) {
		if (check[g[x][i]]) continue;
		check[g[x][i]] = true;
		dfs(g[x][i], cnt + 1);
		check[g[x][i]] = false;
		if (ans == 1) return;
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));
		check[i] = true;
		dfs(i, 0);
		if (ans == 1) break;
	}
	cout << ans << "\n";
}