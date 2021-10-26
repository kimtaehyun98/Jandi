#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m = 0, cnt = 0, l, r;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > m) {
			cnt = 0;
			m = v[i];
			l = i;
			r = i;
		}
		else if (v[i] == m) {
			cnt++;
			r = i;
		}
	}
	int B = l, R = n - r - 1;
	char ans;
	if (B == R) ans = 'X';
	else if (B > R) ans = 'B';
	else ans = 'R';
	cout << ans << "\n";
}