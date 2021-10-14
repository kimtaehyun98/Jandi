#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a, b, c;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			int temp = max(max(a, b), c);
			if (temp <= 0) continue;
			ans += temp;
		}
		cout << ans << "\n";
	}
}