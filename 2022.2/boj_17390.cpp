#include <bits/stdc++.h>
using namespace std;

int n, q, x, l, r;
int pf[300003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	pf[1] = v[0];
	for (int i = 2; i <= n; i++) {
		pf[i] = pf[i - 1] + v[i - 1];
	}
	while (q--) {
		cin >> l >> r;
		cout << pf[r] - pf[l - 1] << "\n";
	}
}