#include <bits/stdc++.h>
using namespace std;

int dp[1004][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; 
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0][0] = 1; dp[n - 1][1] = 1;
	// 증가하는 최장 길이 부분 수열 구하기
	for (int i = 1; i < n; i++) {
		int temp = 0;
		for (int k = 0; k < i; k++) if (arr[i] > arr[k]) temp = max(temp, dp[k][0]);
		dp[i][0] = temp + 1;
	}
	// 감소하는 최장 길이 부분 수열 구하기
	for (int i = n - 2; i >= 0; i--) {
		int temp = 0;
		for (int k = n - 1; k > i; k--) if (arr[i] > arr[k]) temp = max(temp, dp[k][1]);
		dp[i][1] = temp + 1;
	}
	// 바이토닉 부분 수열 구하기
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i][0] + dp[i][1] - 1);
	cout << ans << "\n";
}