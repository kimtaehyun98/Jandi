#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1001][1001];
bool check[1001][1001];

int main() {
	// What is the maximum number of pizza boxes 
	// we can remove without changing the front and side views?
	int n, m, a; ll sum = 0;
	memset(check, false, sizeof(check));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll mr = 0; int x, y;
		for (int k = 0; k < m; k++) {
			cin >> a;
			arr[i][k] = a;
			sum += a;
			if (mr < a) {
				mr = a;
				x = i; y = k;
			}
		}
		check[x][y] = true;
		sum -= arr[x][y];
	}
	for (int k = 0; k < m; k++) {
		ll mc = 0; int x, y;
		for (int i = 0; i < n; i++) {
			if (mc < arr[i][k]) {
				mc = arr[i][k];
				x = i; y = k;
			}
		}
		if (check[x][y] == false) {
			sum -= arr[x][y];
		}
	}
	cout << sum << "\n";
}