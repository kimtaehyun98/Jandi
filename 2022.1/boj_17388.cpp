#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int s, k, h; string ans = "";
	cin >> s >> k >> h;
	if (s + k + h >= 100) ans = "OK";
	else {
		int m = min(s, min(k, h));
		if (m == s) ans = "Soongsil";
		else if (m == k) ans = "Korea";
		else ans = "Hanyang";
	}
	cout << ans << "\n";
}