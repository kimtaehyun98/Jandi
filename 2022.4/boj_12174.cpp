#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n; string str;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cin >> str;
		string ans = "";
		for (int k = 0; k < n; k++) {
			int temp = 0, mul = pow(2, 7);
			for (int s = 0; s < 8; s++) {
				temp += mul * (str[8 * k + s] == 'I' ? 1 : 0);
				mul /= 2;
			}
			ans += temp;
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
}