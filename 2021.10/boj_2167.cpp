#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, k, a, b, c, d;
	int pf[303][303];
	memset(pf, 0, sizeof(pf));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (j == 0) pf[i][j] = x;
			else pf[i][j] = pf[i][j - 1] + x;
		}
	}
	cin >> k;
	while (k--) {
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		int ans = 0;
		for (int i = a; i <= c; i++) {
			ans += b > 0 ? (pf[i][d] - pf[i][b - 1]) :pf[i][d];
		}
		cout << ans << "\n";
	}
}