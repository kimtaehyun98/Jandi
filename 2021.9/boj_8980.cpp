#include <bits/stdc++.h>
using namespace std;

struct box {
	int start;
	int end;
	int x;
};

vector<box> arr;

bool cmp(box & a, box & b) {
	if (a.end != b.end) return a.end < b.end;
	else {
		if (a.start != b.start) return a.start < b.start;
		else return a.x < b.x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	/*
	���� 1: �ڽ��� Ʈ���� ������, �� �ڽ��� �޴� ���������� ������.
	���� 2: Ʈ���� ������ ������ �ǵ��ư��� �ʴ´�.
	���� 3: �ڽ��� �� �Ϻθ� ����� ���� �ִ�.
	*/
	// Ʈ�� �� ��� ����� �� �ִ� �ִ� �ڽ� ���� ���ض�
	int n, c, m, u, v, w, ans = 0;
	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		box temp = { u, v, w };
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	vector<int>cnt(n); // �� ������ ������ �ù� ���� �����ϰ� �ִ� �迭
	for (int i = 0; i < n; i++) cnt[i] = c;
	for (int i = 0; i < m; i++) {
		int s = arr[i].start, e = arr[i].end, temp = INT_MAX;
		// 1) �� ������ �ּҰ� Ž��
		for (int k = s - 1; k < e - 1; k++) temp = min(temp, cnt[k]);
		temp = min(temp, arr[i].x);
		// 2) �� ������ ����
		for (int k = s - 1; k < e - 1; k++) cnt[k] -= temp;
		ans += temp;
	}
	cout << ans << "\n";
}