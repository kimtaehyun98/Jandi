#include <bits/stdc++.h>
using namespace std;

int main() {
	// K개의 그룹으로 나눈 뒤 각각의 그룹에서 맞은 문제 개수의 합을 구하여
	// 그 중 최솟값을 시험 점수로 하기로 하였다.
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int l = 0, r = sum;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0, temp = 0;
		for (int i = 0; i < n; i++) {
			temp += v[i];
			if (temp >= mid) {
				temp = 0;
				cnt++;
			}
		}
		if (cnt >= k) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l - 1 << "\n";
}