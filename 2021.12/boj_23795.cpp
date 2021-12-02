#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	while (1) {
		cin >> n;
		if (n == -1) break;
		ans += n;
	}
	cout << ans << "\n";
}