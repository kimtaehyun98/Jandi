#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int ans = 0, mul = 1;
		for (int k = str.size() - 1; k >= 0; k--) {
			if (str[k] == '1') ans += mul;
			mul *= 2;
		}
		cout << ans << "\n";
	}
}