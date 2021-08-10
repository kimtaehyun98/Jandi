#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 그려진 선들의 총 길이 구하기 (선이 여러 번 그려진 곳은 한번씩 계산)
	int n, x, y, ans = 0;
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	// 시작하는 순으로 정렬
	sort(v.begin(), v.end());
	int s = v[0].first, e = v[0].second;
	for (int i = 1; i < n; i++) {
		int ns = v[i].first, ne = v[i].second;
		if (s <= ns && ns <= e) { // 시작점이 사이에 있다면
			if (e < ne) e = ne;
		}
		else {
			ans += e - s;
			s = ns; e = ne;
		}
	}
	ans += e - s;
	cout << ans << "\n";
}