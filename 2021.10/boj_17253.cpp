#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x = 1, ans = 0;
vector<ll>three;
bool check = false;

int main() {
	cin >> n;
	three.push_back(x);
	for (int i = 1; i <= 39; i++) {
		three.push_back(x * 3);
		x *= 3;
	}
	for (int i = three.size() - 1; i >= 0; i--) {
		if (n >= three[i]) {
			check = true;
			n -= three[i];
		}
		if (n == 0) break;
	}
	if (check && n == 0) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}