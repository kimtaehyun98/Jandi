#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, u, v, ans = 0;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		int pu = Find(u);
		int pv = Find(v);
		if (pu == pv) ans++;
		else parent[pv] = pu;
	}
	for (int i = 1; i <= n; i++) {
		if (Find(i) == i) ans++; // 그룹 개수 체킹
	}
	cout << ans - 1 << "\n";
}