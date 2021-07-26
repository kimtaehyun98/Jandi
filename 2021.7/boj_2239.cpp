#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int arr[10][10];
vector<pii>v;
bool stop = false;

void backTracking(int n) {
	if (n == v.size()) { // 종료 조건
		stop = true;
		return; 
	}
	// 현재 칸 
	pii now = v[n];
	int r = now.first, c = now.second;
	// 현재 칸에 들어갈 수 있는 숫자 검사 (같은 행, 같은 열, 칸은 칸)
	bool temp[10]; memset(temp, true, sizeof(temp));
	for (int i = 0; i < 9; i++) {
		temp[arr[r][i]] = false; temp[arr[i][c]] = false;
	}
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++) {
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++) {
			temp[arr[i][j]] = false;
		}
	}
	// 현재 칸에 가능한 숫자들만 백트래킹에 사용
	vector<int>num;
	for (int i = 1; i <= 9; i++) if (temp[i]) num.push_back(i);
	// 백트래킹
	for (int i = 0; i < num.size(); i++) {
		arr[r][c] = num[i];
		backTracking(n + 1);
		if (stop) return;
		arr[r][c] = 0;
	}
}

int main() {
	// 9 X 9 스도쿠를 푸는 문제이다
	// 백트래킹 사용, 극한의 컷팅
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0) v.push_back(pii(i, j));
		}
	}
	backTracking(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}