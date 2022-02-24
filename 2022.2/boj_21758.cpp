#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001

int arr[MAX_N];
int ps[MAX_N]; // prefix sum

int main() {
	int n, cmp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		ps[i] = i == 1 ? arr[i] : ps[i - 1] + arr[i];
		cmp = max(cmp, arr[i]);
	}
	int ans = 0;
	ans = max(ans, ps[n] - arr[1] - arr[n] + cmp);
	for (int i = 2; i <= n; i++) { // 맨 왼쪽 고정
		ans = max(ans, ps[n] - (arr[1] + arr[i]) + ps[n] - ps[i]);
	}
	for (int i = n - 1; i >= 1; i--) { // 맨 오른쪽 고정
		ans = max(ans, ps[n] + ps[i - 1] -(arr[n] + arr[i]));
	}
	cout << ans << "\n";
}