#include <bits/stdc++.h>
using namespace std;

int arr[51000];

int main() {
	memset(arr, -1, sizeof(arr));
	vector<int>temp;
	for (int i = 1; i <= 225; i++) {
		arr[i * i] = 1;
		temp.push_back(i * i);
	}
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp.size(); j++) {
			int t = temp[i] + temp[j];
			if (t > 50000) break;
			if(arr[t] == -1) arr[temp[i] + temp[j]] = 2;
		}
	}
	int n, ans = 4;
	cin >> n;
	if (arr[n] == -1) {
		for (int i = 1; i < n; i++) {
			int k = n - i;
			if (arr[i] != -1 && arr[k] != -1) ans = min(ans, arr[i] + arr[k]);
			if (ans == 3) break;
		}
	}
	else ans = arr[n];
	cout << ans << "\n";
}