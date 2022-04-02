#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll x, y;
	cin >> x >> y;
	if (x == 0 || x == y) {
		cout << -1 << "\n";
		return 0;
	}
	ll cmp = (y * 100) / x;
	ll l = 1, r = 1000000000, ans = LLONG_MAX;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll temp = ((y + mid) * 100) / (x + mid);
		if (temp != cmp) {
			r = mid - 1;
			ans = min(ans, mid);
		}
		else l = mid + 1;
	}
	if (ans == LLONG_MAX) ans = -1;
	cout << ans << "\n";
}