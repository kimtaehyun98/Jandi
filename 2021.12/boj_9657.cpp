#include <bits/stdc++.h>
using namespace std;

bool dp[1004];

int main() {
	int n;
	cin >> n;
	dp[1] = dp[3] = dp[4] = true;
	for (int i = 5; i <= n; i++) {
		dp[i] = dp[i - 1] && dp[i - 3] && dp[i - 4] ? false : true;
	}
	string ans = dp[n] ? "SK" : "CY";
	cout << ans << "\n";
}