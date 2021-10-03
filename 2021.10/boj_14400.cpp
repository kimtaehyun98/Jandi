#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; ll x, y, ans = 0;
	cin >> n;
	vector<ll>vx, vy;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vx.push_back(x);
		vy.push_back(y);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	x = vx[(n - 1) / 2];
	y = vy[(n - 1) / 2];
	for (int i = 0; i < n; i++) {
		ans += abs(vx[i] - x) + abs(vy[i] - y);
	}
	cout << ans << "\n";
}