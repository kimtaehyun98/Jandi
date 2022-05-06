#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, ans; string a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << "Distances: ";
		for (int k = 0; k < a.size(); k++) {
			ans = (b[k] >= a[k]) ? b[k] - a[k] : b[k] + 26 - a[k];
			cout << ans << " ";
		}
		cout << "\n";
	}
}