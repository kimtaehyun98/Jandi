#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int arr[10][10];
vector<pii>v;
bool stop = false;

void backTracking(int n) {
	if (n == v.size()) { // ���� ����
		stop = true;
		return; 
	}
	// ���� ĭ 
	pii now = v[n];
	int r = now.first, c = now.second;
	// ���� ĭ�� �� �� �ִ� ���� �˻� (���� ��, ���� ��, ĭ�� ĭ)
	bool temp[10]; memset(temp, true, sizeof(temp));
	for (int i = 0; i < 9; i++) {
		temp[arr[r][i]] = false; temp[arr[i][c]] = false;
	}
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++) {
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++) {
			temp[arr[i][j]] = false;
		}
	}
	// ���� ĭ�� ������ ���ڵ鸸 ��Ʈ��ŷ�� ���
	vector<int>num;
	for (int i = 1; i <= 9; i++) if (temp[i]) num.push_back(i);
	// ��Ʈ��ŷ
	for (int i = 0; i < num.size(); i++) {
		arr[r][c] = num[i];
		backTracking(n + 1);
		if (stop) return;
		arr[r][c] = 0;
	}
}

int main() {
	// 9 X 9 ������ Ǫ�� �����̴�
	// ��Ʈ��ŷ ���, ������ ����
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