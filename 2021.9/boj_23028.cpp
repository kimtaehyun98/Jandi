#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, x, y;
	cin >> n >> a >> b;
	n = 8 - n;
	for (int i = 1; i <= 10; i++) {
		cin >> x >> y;
		if (i > n) continue;
		int temp = 0;
		for (int k = 0; k < x; k++) {
			a += 3;
			b += 3;
			temp++;
		}
		if (temp == 6) continue;
		for (int k = 0; k < y; k++) {
			if (temp >= 6) break;
			b += 3; temp++;
		}
	}
	if (a >= 66 && b >= 130) cout << "Nice" << "\n";
	else cout << "Nae ga wae" << "\n";
}