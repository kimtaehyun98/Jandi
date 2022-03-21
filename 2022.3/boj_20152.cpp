#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[31][31];

int main() {
	int n, m;
	cin >> n >> m;
	int temp = min(n, m);
	n -= temp; m -= temp;
	if (n > m) swap(n, m);
	temp = abs(n - m);
	for (int i = 0; i <= temp; i++) {
		for (int j = 0; j <= temp; j++) {
			if (j == 0) dp[i][j] = 1;
			else if (j > i) continue;
			else if (i == j) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[temp][temp] << "\n";
}