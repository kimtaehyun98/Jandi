#include <bits/stdc++.h>
using namespace std;

bool up[1004], down[1004];

int main() {
	int n, a;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a >= 0) {
			if (!up[a]) {
				v.push_back(a);
				up[a] = true;
			}
		}
		else {
			a = abs(a);
			if (!down[a]) {
				v.push_back(-1 * a);
				down[a] = true;
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
}