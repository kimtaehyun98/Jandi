#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[107];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i <= 3) dp[i] = i;
		else {
			ll cmp = i;
			for (int k = 3; k < i; k++) {
				cmp = max(cmp, (k - 1) * dp[i - k]);
			}
			dp[i] = cmp;
		}
	}
	cout << dp[n] << "\n";
}