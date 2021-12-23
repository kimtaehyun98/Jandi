#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = (a * 24 + b) * 60 + c - 16511;
	if (ans < 0) ans = -1;
	cout << ans << "\n";
}