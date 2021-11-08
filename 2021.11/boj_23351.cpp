#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, a, b, ans = 0;
	cin >> n >> k >> a >> b;
	if (k < n / a) {
		ans += k;
	}
	else {
		while (1) {
			k += b - (n / a);
			ans += (n / a);
			if (k < n / a) {
				ans += k;
				break;
			}
		}
	}
	cout << ans << "\n";
}