#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	while (1) {
		cin >> str;
		if (str == "0") break;
		int s = str.size();
		s /= 2;
		bool check = true;
		for (int i = 0; i < s; i++) {
			if (str[i] != str[str.size() - 1 - i]) {
				check = false;
				break;
			}
		}
		string ans = check ? "yes" : "no";
		cout << ans << "\n";
	}
}