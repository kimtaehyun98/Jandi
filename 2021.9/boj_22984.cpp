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
	// 작은 전구의 기대값
	for (int i = 0; i < n - 1; i++) {
		ans += v[i] * (1 - v[i + 1]); // 왼쪽 큰 전구만 켜짐 
		ans += (1 - v[i]) * v[i + 1]; // 오른쪽 큰 전구만 켜짐
	}
	printf("%0.8lf\n", ans);
}