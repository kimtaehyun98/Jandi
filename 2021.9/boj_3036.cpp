#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 1; i < n; i++) {
		int g = gcd(v[0], v[i]);
		cout << v[0] / g << "/" << v[i] / g << "\n";
	}
}