#include <bits/stdc++.h>
using namespace std;

bool row[55], col[55];

int main() {
	int n, m; char s;
	cin >> n >> m;
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s;
			if (s == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	int r = 0, c = 0;
	for (int i = 0; i < n; i++) if (row[i] == false) r++;
	for (int j = 0; j < m; j++) if (col[j] == false) c++;
	cout << max(r, c) << "\n";
}