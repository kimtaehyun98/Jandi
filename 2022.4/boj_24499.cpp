#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, temp = 0, ans = 0;
	cin >> n >> k;
	vector<int>v(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i + n] = v[i];
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i >= k) {
			ans = max(ans, temp);
			temp -= v[i - k];
		}
		temp += v[i];
	}
	ans = max(ans, temp);
	cout << ans << "\n";
}