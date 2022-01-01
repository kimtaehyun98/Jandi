#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>prime;
	for (int i = 2; i <= 200; i++) {
		bool p = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				p = false;
				break;
			}
		}
		if (p) prime.push_back(i);
	}
	for (int i = 0; i < prime.size() - 1; i++) {
		int temp = prime[i] * prime[i + 1];
		if (temp > n) {
			cout << temp << "\n";
			break;
		}
	}
}