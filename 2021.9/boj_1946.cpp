#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pii>v;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back(pii(x, y));
		}
		sort(v.begin(), v.end());
		int cmp = v[0].second, ans = 1;
		for (int i = 1; i < n; i++) {
			if (v[i].second <= cmp) ans++;
			cmp = min(cmp, v[i].second);
		}
		cout << ans << "\n";
	}
}