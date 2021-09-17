#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string arr[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

ll change(string s, int cnt) {
	ll mul = 1;
	for (ll i = 0; i < 10; i++) {
		if (arr[i] == s) {
			if (cnt == 0) return i;
			else return mul;
		}
		mul *= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;
	ll ans = (change(a, 0) * 10 + change(b, 0)) * change(c, 1);
	cout << ans << "\n";
}