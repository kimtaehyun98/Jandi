#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, x;
	while (1) {
		cin >> x;
		if (cin.eof()) break;
		x *= 10000000;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		pii ans = pii(0, 0); bool check = false;
		for (int i = 0; i < n; i++) {
			int a = v[i];
			int l = i + 1, r = n - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (a + v[mid] == x) {
					if (check) {
						if (abs(ans.first - ans.second) < abs(a - v[mid])) {
							ans = pii(a, v[mid]);
						}
					}
					else ans = pii(a, v[mid]);
					check = true;
					break;
				}
				if (a + v[mid] > x) r = mid - 1;
				else l = mid + 1;
			}
		}
		if (check) cout << "yes " << ans.first << " " << ans.second << "\n";
		else cout << "danger" << "\n";
	}
}