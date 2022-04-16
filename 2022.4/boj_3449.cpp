#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; string a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int s = a.size(), cnt = 0;
		for (int i = 0; i < s; i++) {
			if (a[i] != b[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << "." << "\n";
	}
}