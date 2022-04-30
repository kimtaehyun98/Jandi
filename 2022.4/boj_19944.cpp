#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; string ans;
	cin >> n >> m;
	if (m <= 2) ans = "NEWBIE!";
	else if (m <= n) ans = "OLDBIE!";
	else ans = "TLE!";
	cout << ans << "\n";
}