#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; string pattern, cmp;
	cin >> n;
	cin >> pattern;
	for (int i = 0; i < n; i++) {
		cin >> cmp;
		if (cmp.size() < pattern.size() - 1) {
			cout << "NE" << "\n";
			continue;
		}
		bool front = true;
		for (int k = 0; k < pattern.size(); k++) {
			if (pattern[k] == '*') break;
			if (k >= cmp.size() || pattern[k] != cmp[k]) {
				front = false;
				break;
			}
		}
		bool back = true;
		if (front) {
			int c = cmp.size() - 1;
			for (int k = pattern.size() - 1; k >= 0; k--) {
				if (pattern[k] == '*') break;
				if (c < 0 || pattern[k] != cmp[c]) {
					back = false;
					break;
				}
				c--;
			}
		}
		string ans = "";
		if (front && back) ans = "DA";
		else ans = "NE";
		cout << ans << "\n";
	}
}