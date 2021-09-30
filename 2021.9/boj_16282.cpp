#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dd(ll a, ll c) {
	ll ret = 1;
	while (c--) ret *= a;
	return ret;
}

ll func(ll x) {
	return x + (x + 1) * (dd(2, x + 1) - 1);
}

int main() {
	ll n, prev = 0;
	cin >> n;
	for (ll i = 1; i <= 64; i++) {
		ll temp = func(i);
		if (prev < n && n <= temp) {
			cout << i << "\n";
			break;
		}
		else prev = temp;
	}
}