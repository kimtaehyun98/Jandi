#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n; char c; pii s, e;
vector<pii> points[4];
char arr[101][101];
string ans[] = { "Assassin", "Healer", "Mage", "Tanker" };

int getDis(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int calc(int idx) {
	int ret = INT_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == i) continue;
			for (int k = 0; k < 3; k++) {
				if (k == i || k == j) continue;
				int temp = getDis(s, points[idx][i]) + getDis(points[idx][i], points[idx][j]) + getDis(points[idx][j], points[idx][k]) + getDis(points[idx][k], e);
				if (temp < ret) {
					ret = temp;
				}
			}
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			pii now = pii(i, j);
			if (arr[i][j] == 'H') s = now;
			else if (arr[i][j] == '#') e = now;
			else if (arr[i][j] == 'J') points[0].push_back(now);
			else if (arr[i][j] == 'C') points[1].push_back(now);
			else if (arr[i][j] == 'B') points[2].push_back(now);
			else if (arr[i][j] == 'W') points[3].push_back(now);
			else continue;
		}
	}
	int cmp = INT_MAX, idx = 0;
	for (int i = 0; i < 4; i++) {
		int temp = calc(i);
		if (cmp > temp) { 
			cmp = temp;
			idx = i;
		}
	}
	cout << ans[idx] << "\n";
}