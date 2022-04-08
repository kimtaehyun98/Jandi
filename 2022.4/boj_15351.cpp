#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; string str;
	cin >> n;
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		int ans = 0;
		for (int k = 0; k < str.size(); k++) {
			if (str[k] == ' ') continue;
			ans += (str[k] - 'A') + 1;
		}
		if (ans == 100) cout << "PERFECT LIFE" << "\n";
		else cout << ans << "\n";
	}
}