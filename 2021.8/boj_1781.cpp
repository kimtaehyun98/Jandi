#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int parent[200002];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int px = find(x), py = find(y);
	x < y ? parent[py] = px : parent[px] = py;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; ll w, t, ans = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) parent[i] = i;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		cin >> t >> w;
		v.push_back(pll(w, t));
	}
	sort(v.begin(), v.end(), greater<pll>());
	// union find 사용 - 최선의 deadline을 가지고 있기
	for (int i = 0; i < n; i++) {
		w = v[i].first;
		t = v[i].second;
		int p = find((int)t);
		if (p == 0) continue;
		ans += w;
		Union(p, p - 1);
	}
	cout << ans << "\n";
}