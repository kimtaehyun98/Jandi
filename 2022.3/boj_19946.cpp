#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
	ll n, ans = 64;
	cin >> n;
	while (n != 0) {
		if (n % 2 == 0) {
			ans--;
			n /= 2;
		}
		else {
			break;
		}
	}
	cout << ans << "\n";
}