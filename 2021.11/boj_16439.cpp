#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m;
	vector<int>v[33];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			for (int k = j + 1; k <= m; k++) {
				int temp = 0;
				for (int a = 0; a < n; a++) {
					temp += max(max(v[a][i - 1], v[a][j - 1]), v[a][k - 1]);
				}
				ans = max(temp, ans);
			}
		}
	}
	cout << ans << "\n";
}