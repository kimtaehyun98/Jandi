#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y, a, cnt = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x >> y;
	for (int i = 0; i < n; i++) if (v[i] >= y)cnt++;
	cout << (n * x) / 100 << " " << cnt << "\n";
	
}