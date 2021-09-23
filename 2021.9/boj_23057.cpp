#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
set<int>s;

void bt(int cnt, int start, int stop, int sum, vector<int>& v) {
	if (cnt == stop) {
		s.insert(sum);
		return;
	}
	for (int i = start; i < n; i++) {
		sum += v[i];
		bt(cnt + 1, i + 1, stop, sum, v);
		sum -= v[i];
	}
}

int main() {
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ans += v[i];
	}
	// 최대 20개의 수가 들어옴 -> 20*20 -> 20C1 + 20C2 + 20C3 + ... 20C20 = 2^20 = 약 1048576 (백만)
	// 따라서 만들 수 있는 수를 모두 구한 뒤 전체에서 빼면 됨 (여기서 중복 제거하기 위해 set 사용하면 될듯)
	for (int i = 1; i <= n; i++) bt(0, 0, i, 0, v);
	cout << ans - s.size() << "\n";
}