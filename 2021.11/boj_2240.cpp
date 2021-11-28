#include <bits/stdc++.h>
using namespace std;

int arr[1004];
int dp[1004][33];

int main() {
	int t, w, ans = 0, cnt = 0;
	cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> arr[i];
	// dp[i][j] = i초에 j번 만큼 움직였을 때 최대값
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][0] + (arr[i] == 1);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (arr[i] == (j % 2 == 0 ? 1 : 2));
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}