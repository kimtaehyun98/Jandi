#include <bits/stdc++.h>
using namespace std;

int p[6] = { 1,2,3,3,4,10 };
int s[7] = { 1,2,2,2,3,5,10 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, x; string ans;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int sp = 0, ss = 0;
		for (int i = 0; i < 6; i++) {
			cin >> x;
			sp += p[i] * x;
		}
		for (int i = 0; i < 7; i++) {
			cin >> x;
			ss += s[i] * x;
		}
		if (sp > ss) {
			ans = "Good triumphs over Evil";
		}
		else if (sp < ss) {
			ans = "Evil eradicates all trace of Good";
		}
		else ans = "No victor on this battle field";
		cout << "Battle " << k + 1 << ": " << ans << "\n";
	}
}