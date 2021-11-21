#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dp[17];

int main() {
	int n, t, p;
	cin >> n;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		v[i] = pii(t, p);
	}
	for (int i = n; i >= 1; i--) {
		if (i + v[i].first - 1 <= n) { // 해당 날짜의 상담이 가능하다면
			int temp = 0;
			for (int j = n; j >= i + v[i].first; j--) {
				temp = max(temp, dp[j]);
			}
			dp[i] = max(dp[i + 1], temp + v[i].second);
		}
		else dp[i] = dp[i + 1];
	}
	cout << dp[1] << "\n";
}