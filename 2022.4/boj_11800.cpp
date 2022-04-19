#include <bits/stdc++.h>
using namespace std;

string nonSame[] = { "Yakk" , "Doh" , "Seh" , "Ghar" , "Bang" , "Sheesh" };
string same[] = { "Habb Yakk" , "Dobara" , "Dousa" , "Dorgy" , "Dabash" , "Dosh" };

int main() {
	int t, a, b; string ans;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a == 6 && b == 5) ans = "Sheesh Beesh";
		else if (a == b) ans = same[a - 1];
		else {
			ans = nonSame[a - 1] + " " + nonSame[b - 1];
		}
		cout << "Case " << i << ": " << ans << "\n";
	}
}