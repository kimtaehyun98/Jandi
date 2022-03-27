#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
typedef long long ll;

ll dp[41][10][(1 << 10)];

int main() {
	int n; ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k <= 1024; k++) {
				if (i == 1) {
					if (j == 0) continue; 
					dp[i][j][(1 << j)] = 1;
					continue;
				}
				if(j != 0) dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % MOD;
				if(j != 9) dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % MOD;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i][(1 << 10) - 1];
		ans %= MOD;
	}
	cout << ans << "\n";
}