#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, x, y, z;
	cin >> a >> b >> c;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int k = 0; k < 3; k++) {
			cin >> x >> y >> z;
			temp += (x * a) + (y * b) + (z * c);
		}
		ans = max(temp, ans);
	}
	cout << ans << "\n";
}