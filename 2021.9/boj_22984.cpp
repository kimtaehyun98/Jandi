#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

vector<double>v(100001);

int main() {
	int n; double ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ans += v[i];
	}
	// ���� ������ ��밪
	for (int i = 0; i < n - 1; i++) {
		ans += v[i] * (1 - v[i + 1]); // ���� ū ������ ���� 
		ans += (1 - v[i]) * v[i + 1]; // ������ ū ������ ����
	}
	printf("%0.8lf\n", ans);
}