#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	ans = n;
	while (n != 0) {
		ans += n / m;
		n /= m;
	}
	cout << ans << "\n";
}