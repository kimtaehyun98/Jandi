#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t, a, b, u;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		u = a - b;
		cout << b - u << " " << u << "\n";
	}
}