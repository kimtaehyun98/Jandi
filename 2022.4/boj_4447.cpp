#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str, ans; int n;
	cin >> n;
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		int g = 0, b = 0;
		for (int k = 0; k < str.size(); k++) {
			if (str[k] == 'g' || str[k] == 'G') g++;
			if (str[k] == 'b' || str[k] == 'B') b++;
		}
		if (g > b) ans = " is GOOD";
		else if (g < b) ans = " is A BADDY";
		else ans = " is NEUTRAL";
		cout << str << ans << "\n";
	}

}