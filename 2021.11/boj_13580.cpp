#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	string ans;
	cin >> a >> b >> c;
	if (a == b || b == c || c == a) ans = "S";
	else if (a == b + c || b == a + c || c == a + b) ans = "S";
	else ans = "N";
	cout << ans << "\n";
}