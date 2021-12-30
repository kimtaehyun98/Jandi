#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll ans = gcd(a, b);
	for (int i = 0; i < ans; i++) cout << "1";
}