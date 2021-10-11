#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 0, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		if (v[i] == cnt) {
			cnt = cnt == 2 ? 0 : cnt + 1;
			ans++;
		}
	}
	cout << ans << "\n";
}