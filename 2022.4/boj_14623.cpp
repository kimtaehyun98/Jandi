#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, ans = ""; ll x = 0, y = 0;
	cin >> a >> b;
	ll mul = 1;
	for (int i = a.size() - 1; i >= 0; i--) {
		x += (a[i] - '0') * mul;
		mul *= 2;
	}
	mul = 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		y += (b[i] - '0') * mul;
		mul *= 2;
	}
	x = x * y;
	mul = 1;
	while (x != 0) {
		ans += x % 2 == 0 ? '0' : '1';
		x /= 2;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}