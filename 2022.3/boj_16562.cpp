#include <bits/stdc++.h>
using namespace std;

int cost[10001], parent[10001], cmp[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y) {
		parent[y] = x;
		cost[y] = min(cost[x], cost[y]);
		cost[x] = min(cost[x], cost[y]);
	}
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int main() {
	int n, m, v, w, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> v >> w;
		Union(v, w);
	}
	int prev = Find(1);
	int sum = cost[prev];
	for (int i = 2; i <= n; i++) {
		int p = Find(i);
		if (p != prev) {
			sum += cost[p];
			Union(p, prev);
			prev = p;
		}
	}
	if (c < sum) cout << "Oh no" << "\n";
	else cout << sum << "\n";
}
