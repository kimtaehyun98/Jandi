#include <bits/stdc++.h>
using namespace std;

string change(int k) {
	string ret = "";
	int cnt = 0;
	while (k > 0) {
		if (k % 2 == 0) ret = "V" + ret;
		else ret = "µþ±â" + ret;
		k /= 2;
		cnt++;
	}
	for (int i = cnt; i < 4; i++) ret = "V" + ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 15) cout << change(n) << "\n";
		else {
			n -= 16;
			int a = n / 14;
			int b = n % 14;
			if (a % 2 == 0) {
				cout << change(14 - b) << "\n";
			}
			else {
				cout << change(b + 2) << "\n";
			}
		}
	}
}