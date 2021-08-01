#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int parent[500007];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		int px = find(x), py = find(y);
		if (px == py) {
			cout << i << "\n";
			return 0;
		}
		else parent[px] = py;
	}
	cout << 0 << "\n";
}