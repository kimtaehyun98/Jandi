#include <bits/stdc++.h>
using namespace std;

int r, c, t, ans = 0;
int arr[41][41];

int filter(int x, int y) {
	vector<int>v;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(), v.end());
	return v[4];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;
	for (int i = 0; i <= r - 3; i++) {
		for (int j = 0; j <= c - 3; j++) {
			int temp = filter(i, j);
			if (temp >= t) ans++;
		}
	}
	cout << ans << "\n";
}