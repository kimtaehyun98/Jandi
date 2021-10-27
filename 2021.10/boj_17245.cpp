#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1004][1004];

int main() {
	int n; ll x, m = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x > m) m = x;
			arr[i][j] = x;
			sum += x;
		}
	}
	ll l = 0, r = m, ans = LLONG_MAX;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp += arr[i][j] < mid ? arr[i][j] : mid;
			}
		}
		// cout << (double)temp / (double)sum << "\n";
		if ((double)temp / (double)sum >= 0.5) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans == LLONG_MAX) ans = 0;
	cout << ans << "\n";
}