#include <bits/stdc++.h>
using namespace std;

char arr[5][10001], ans[5][10001];

int main() {
	string str;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int k = 0; k < str.size(); k++) {
			arr[i][k] = str[k];
		}
	}
	int s = str.size();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s; j++) {
			ans[i][j] = '.';
		}
	}
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < 5; i++) {
			if (arr[i][j] == 'm') {
				ans[i - 2][j] = 'o';  ans[i - 1][j] = 'w';
				ans[i][j] = 'l'; ans[i + 1][j] = 'n';
			}
			else if (arr[i][j] == 'w') {
				ans[i][j] = 'o'; ans[i + 1][j] = 'm';
				ans[i + 2][j] = 'l'; ans[i + 3][j] = 'n';
			}
			else if (arr[i][j] == 'L') {
				ans[i - 1][j] = 'o'; ans[i][j] = 'L';
				ans[i + 1][j] = 'n';
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
}