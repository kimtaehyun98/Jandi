#include <bits/stdc++.h>
using namespace std;

bool dp[55][1004]; // dp[i][j] = i번째 곡 일때 볼륨 j가 가능한지

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	dp[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + v[i] <= m) dp[i][j + v[i]] = true;
				if (j - v[i] >= 0) dp[i][j - v[i]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) if(dp[n][i]) ans = max(ans, i);
	cout << ans << "\n";
}