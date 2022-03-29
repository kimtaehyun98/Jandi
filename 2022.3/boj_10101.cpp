#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	string ans;
	cin >> a >> b >> c;
	if (a == b && b == c && a == 60) ans = "Equilateral";
	else if (a + b + c == 180) {
		if (a == b || b == c || a == c) ans = "Isosceles";
		else ans = "Scalene";
	}
	else ans = "Error";
	cout << ans << "\n";
}