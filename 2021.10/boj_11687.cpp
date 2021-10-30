#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n = INT_MAX;
	bool check = false;
	cin >> m;
	int l = 1, r = 1000000000;
	while (l <= r) {
		int mid = (l + r) / 2;
		int temp = 0;
		int mul = 5, x = 5;
		for (int i = 5; i <= mid; i *= 5) {
			temp += mid / i;
		}
		if (temp >= m) {
			if (temp == m) {
				n = min(n, mid);
				check = true;
			}
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (check) cout << n << "\n";
	else cout << -1 << "\n";
}