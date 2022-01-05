#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 1, n = str.size();
	for (int i = 0; i < n / 2; i++) {
		if (str[i] != str[n - i - 1]) {
			ans = 0;
			break;
		}
	}
	cout << ans << "\n";
}