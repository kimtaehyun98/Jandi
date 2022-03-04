#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, temp = 0, ni = 1000, mj = 1000;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		temp = 0;
		int tmj = 1000;
		for (int j = 0; j < m; j++) {
			temp++;
			if (j == m - 1 || arr[i][j] != arr[i][j + 1]) {
				tmj = min(tmj, temp);
				temp = 0;
			}
			
		}
		mj = min(mj, tmj);
		
	} 
	for (int j = 0; j < m; j++) {
		temp = 0;
		int tni = 1000;
		for (int i = 0; i < n; i++) {
			temp++;
			if (i == n - 1 || arr[i][j] != arr[i + 1][j]) {
				tni = min(tni, temp);
				temp = 0;
			}
		}
		ni = min(ni, tni);
	}
	cout << n / ni << " " << m / mj << "\n";
	for (int i = 0; i < n; i++) {
		if (i % ni != 0) continue;
		for (int j = 0; j < m; j++) {
			if (j % mj == 0) cout << arr[i][j];
		}
		cout << "\n";
	}
}