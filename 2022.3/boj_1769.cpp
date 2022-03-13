#include <bits/stdc++.h>
using namespace std;

string change(string str) {
	int ret = 0;
	for (int i = 0; i < str.size(); i++) {
		ret += str[i] - '0';
	}
	return to_string(ret);
}

int main() {
	string str;
	cin >> str;
	int cnt = 0;
	while (1) {
		if (str.size() <= 1) {
			cout << cnt << "\n";
			string ans = stoi(str) % 3 == 0 ? "YES" : "NO";
			cout << ans << "\n";
			break;
		}
		else {
			str = change(str);
			cnt++;
		}
	}
}

