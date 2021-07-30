#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = INT_MAX;

vector<ll>arr(100007);
vector<pll>MinMaxTree(300007); // min = first, max = second
int id[100007];

pll init(int node, int start, int end) {
	if (start == end) { // 리프 노드
		return MinMaxTree[node] = pll(start, start);
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

pll update(int node, int start, int end, int index, ll num) {
	if (index < start || end < index) return MinMaxTree[node];
	if (start == end) MinMaxTree[node] = pll(num, num);
	else {
		pll left = update(node * 2, start, (start + end) / 2, index, num);
		pll right = update(node * 2 + 1, (start + end) / 2 + 1, end, index, num);
		MinMaxTree[node].first = min(left.first, right.first);
		MinMaxTree[node].second = max(left.second, right.second);
	}
	return MinMaxTree[node];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n, k ,q, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) id[i] = i;
		init(1, 0, n - 1);
		for (int i = 0; i < k; i++) {
			cin >> q >> a >> b;
			if (q == 0) { // a 선반과 b 선반 교체
				swap(id[a], id[b]);
				update(1, 0, n - 1, a, id[a]);
				update(1, 0, n - 1, b, id[b]);
			}
			else {
				pll temp = query(1, 0, n - 1, a, b);
				if (temp.first == a && temp.second == b) cout << "YES" << "\n";
				else cout << "NO" << "\n";
			}
		}
	}
}