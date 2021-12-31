#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (x == n) ans++;
	}
	cout << ans << "\n";
}