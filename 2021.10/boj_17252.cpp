#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = 0, temp = 0, x = 1;
vector<ll>three;

void bt(ll cnt, ll stop, int start) {
	if (cnt == stop) {
		if (temp == n) ans++;
		return;
	}
	for (int i = start; i < three.size(); i++) {
		temp += three[i];
		bt(cnt + 1, stop, i + 1);
		temp -= three[i];
	}
}

int main() {
	cin >> n;
	three.push_back(x);
	for (int i = 1; i <= 19; i++) {
		if (x * 3 > n) break;
		three.push_back(x * 3);
		x *= 3;
	}
	for (int i = 0; i < three.size(); i++) {
		bt(0, i + 1, 0);
		if (ans > 0) break;
	}
	if (ans > 0) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}