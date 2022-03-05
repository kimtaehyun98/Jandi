#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int flag = arr[n - 1], ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		flag--;
		if (flag > arr[i]) flag = arr[i];
		else {
			ans += arr[i] - flag;
		}
	}
	cout << ans << "\n";
	
}