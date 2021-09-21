#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || j == n - 1 || j == i || j == n - i - 1) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	// 홀수이면 중간에 한줄 출력
	if (n % 2 == 1) {
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1 || i == n / 2) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = (n / 2) - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || j == n - 1 || j == i || j == n - i - 1) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}