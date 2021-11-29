#include <bits/stdc++.h>
using namespace std;

int dp[1004];

int main() {
	int n;
	cin >> n;
	dp[1] = 0; dp[2] = 1; dp[3] = 0;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] == 0 || dp[i - 3] == 0) ? 1 : 0;
	}
	string ans = dp[n] == 0 ? "CY" : "SK";
	cout << ans << "\n";
}