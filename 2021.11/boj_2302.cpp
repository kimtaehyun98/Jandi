#include <bits/stdc++.h>
using namespace std;

int dp[41];
bool vip[41];

int main() {
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		vip[x] = true; // ∞Ì¡§ºÆ
	}
	dp[0] = 1;  dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int cnt = 0, ans = 1;
	for (int i = 1; i <= n; i++) {
		if (vip[i]) {
			ans *= dp[cnt];
			cnt = 0;
		}
		else cnt++;
	}
	ans *= dp[cnt];
	cout << ans << "\n";
}