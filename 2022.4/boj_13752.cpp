#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int s = 0; s < k; s++) {
			cout << "=";
		}
		cout << "\n";
	}
}