#include <bits/stdc++.h>
using namespace std;

int r, c, ans = 0;
int dx[] = { 0, 0, 1, 1 };
int dy[] = { 0, 1, 0, 1 };

void divConq(int n, int x, int y) {
	// 해당 좌표에 왔다면 return 
	if (x == r && y == c) {
		return;
	}
	// n*n을 4등분 하여서 어디 있는지 확인
	int s = n / 2;
	for (int k = 0; k < 4; k++) {
		int nx = x + s * dx[k];
		int ny = y + s * dy[k];
		if (nx <= r && r < nx + s && ny <= c && c < ny + s) {
			divConq(s, nx, ny);
			return;
		}
		else ans += s * s;
	}
}

int main() {
	int n;
	cin >> n >> r >> c;
	divConq(1 << n, 0, 0);
	cout << ans << "\n";
}
