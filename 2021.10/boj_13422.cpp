#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<int>v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int s = 0, e = 0, cnt = 0, temp = 0, ans = 0;
		// 다시 s가 0이 되면 break;
		while (1) {
			if (cnt < m) {
				cnt++;
				temp += v[e++];
				if (e >= n) e -= n;
			}
			else {
				if (temp < k) ans++;
				temp -= v[s++];
				cnt--;
				if (s == n || n == m) break;
			}			
		}
		cout << ans << "\n";
	}
}