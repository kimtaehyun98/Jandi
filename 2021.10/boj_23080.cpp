#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string str, ans = "";
	cin >> n;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (i % n == 0) ans += str[i];
	}
	cout << ans << "\n";
}