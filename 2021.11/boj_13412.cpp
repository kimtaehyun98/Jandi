#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	// N <= 1��
	// N���� �۰ų� ���� �� ���μ��� �ּҰ������ ���� ����
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int x = 1, ans = 0;
		while (1) {
			if (x * x > n) break;
			if (n % x == 0) {
				if (gcd(x, n / x) == 1) ans++;
			}
			x++;
		}
		cout << ans << "\n";
	}
}