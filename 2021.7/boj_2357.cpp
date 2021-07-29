#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = INT_MAX;

vector<ll>arr(100007);
vector<pll>MinMaxTree(300007); // min = first, max = second

pll init(int node, int start, int end) {
	if (start == end) { // 리프 노드
		return MinMaxTree[node] = pll(arr[start], arr[start]);
	}
	else {
		pll left = init(node * 2, start, (start + end) / 2), right = init(node * 2 + 1, (start + end) / 2 + 1, end);
		return MinMaxTree[node] = pll(min(left.first, right.first), max(left.second, right.second));
	}
}

pll query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return pll(INF, 0);
	if (left <= start && end <= right) return MinMaxTree[node];
	pll l = query(node * 2, start, (start + end) / 2, left, right), r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return pll(min(l.first, r.first), max(l.second, r.second));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pll ans = query(1, 0, n - 1, a - 1, b - 1);
		cout << ans.first << " " << ans.second << "\n";
	}
}