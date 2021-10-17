#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = v[i] + v[j];
				if (temp % 2 != 0) continue;
				int num = temp / 2;
				int l = 0, r = n - 1;
				while (l <= r) {
					int m = (l + r) / 2;
					if (v[m] < num) l = m + 1;
					else if (v[m] > num) r = m - 1;
					else {
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
}