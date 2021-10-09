#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str, ans = "";
	cin >> str;
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			flag = true;
			continue;
		}
		if (flag) {
			ans += str[i];
			flag = false;
		}
	}
	cout << ans << "\n";
}