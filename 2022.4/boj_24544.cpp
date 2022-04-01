#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x, sum = 0, nreg = 0;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) nreg += v[i];
	}
	cout << sum << " " << nreg << "\n";
}