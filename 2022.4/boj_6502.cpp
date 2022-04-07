#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r, w, l, t = 1;
	while (1) {
		cin >> r;
		if (r == 0) break;
		cin >> w >> l;
		cout << 4 * r * r << " " << w * w + l * l << "\n";
		if (4 * r * r >= (w * w + l * l)) {
			cout << "Pizza " << t << " fits on the table." << "\n";
		}
		else cout << "Pizza " << t << " does not fit on the table." << "\n";
		t++;
	}
}