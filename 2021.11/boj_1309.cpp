#include <bits/stdc++.h>
using namespace std;
const int MOD = 9901;

int dp[100007][3];

int main() {
	int n;
	cin >> n;
	dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % MOD << "\n";
}