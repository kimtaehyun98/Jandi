#include <bits/stdc++.h>
using namespace std;

int dp[100000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	dp[0][0] = 0; dp[0][1] = cost[0]; dp[0][2] = 0;
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + cost[i];
		dp[i][2] = dp[i - 1][1] + cost[i] / 2;
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";
}