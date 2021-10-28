#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, l = 1, r = 0, ans = INT_MAX;
	cin >> n >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
		r = max(r, v[i]);
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		int temp = 0;
		for (int i = 0; i < m; i++) {
			temp += v[i] / mid;
			if (v[i] % mid != 0) temp++;
		}
		if (temp <= n) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << "\n";
}