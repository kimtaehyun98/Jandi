#include <bits/stdc++.h>
using namespace std;

int ans[100001];

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ans[a] += 1;
		ans[b] += 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}