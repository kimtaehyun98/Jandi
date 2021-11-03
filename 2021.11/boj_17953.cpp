#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[11][100007];
ll dp[11][100007];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			cin >> arr[i][k];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (i == 0) {
				dp[k][i] = arr[k][i];
				continue;
			}
			ll temp = 0;
			for (int s = 0; s < m; s++) {
				if (k == s) {
					temp = max(temp, dp[s][i - 1] + arr[k][i] / 2);
				}
				else {
					temp = max(temp, dp[s][i - 1] + arr[k][i]);
				}
			}
			dp[k][i] = temp;
		}
	}
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		ans = max(ans, dp[i][n - 1]);;
	}
	cout << ans << "\n";
}