#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009, s = 1000007;

ll dp[s];

int main() {
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < s; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}