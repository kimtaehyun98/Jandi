#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	char prev = str[0];
	int ans = 10;
	for (int i = 1; i < str.size(); i++) {
		if (prev == str[i]) ans += 5;
		else {
			prev = str[i];
			ans += 10;
		}
	}
	cout << ans << "\n";
}