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
	조건 1: 박스를 트럭에 실으면, 이 박스는 받는 마을에서만 내린다.
	조건 2: 트럭은 지나온 마을로 되돌아가지 않는다.
	조건 3: 박스들 중 일부만 배송할 수도 있다.
	*/
	// 트럭 한 대로 배송할 수 있는 최대 박스 수를 구해라
	int n, c, m, u, v, w, ans = 0;
	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		box temp = { u, v, w };
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	vector<int>cnt(n); // 각 구간의 가능한 택배 양을 저장하고 있는 배열
	for (int i = 0; i < n; i++) cnt[i] = c;
	for (int i = 0; i < m; i++) {
		int s = arr[i].start, e = arr[i].end, temp = INT_MAX;
		// 1) 각 구간별 최소값 탐색
		for (int k = s - 1; k < e - 1; k++) temp = min(temp, cnt[k]);
		temp = min(temp, arr[i].x);
		// 2) 각 구간별 갱신
		for (int k = s - 1; k < e - 1; k++) cnt[k] -= temp;
		ans += temp;
	}
	cout << ans << "\n";
}