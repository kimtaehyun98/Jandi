#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	// next�� ������ + 1 ���� �۰ų� ���ٸ� ������ ���� �� ����
	int sum = 1;
	for (int i = 1; i < n; i++) {
		if (sum + 1 >= v[i]) sum += v[i];
		else break;
	}
	if (v[0] != 1) sum = 0;
	cout << sum + 1 << "\n";
}