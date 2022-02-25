#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

char arr[10][10];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 검사 = 4개가 연속되어 있는지, 그 다음칸이 비어있는지
bool solve(int x, int y) {
	int nx, ny, xc, xd;
	for (int k = 0; k < 8; k++) {
		nx = x; ny = y; xc = 1; xd = 0;
		for (int s = 0; s < 4; s++) {
			nx = nx + dx[k];
			ny = ny + dy[k];
			if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
				if (arr[nx][ny] == 'X') xc++;
				else if (arr[nx][ny] == '.') xd++;
				else break;
			}
			else break;
		}
		if (xc >= 4 && xd == 1) return true;
	}
	return false;
}

int main() {
	string str;
	for (int i = 0; i < 10; i++) {
		cin >> str;
		for (int j = 0; j < 10; j++) {
			arr[i][j] = str[j];
		}
	}

	// 가로, 세로, 대각선 총 8방향 검사
	int stop = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 'X') {
				stop = solve(i, j);
				if (stop == 1) break;
			}
		}
		if (stop == 1) break;
	}
	cout << stop << "\n";
}