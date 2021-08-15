#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll arr[1000007];
ll tree[4000007];

// init
ll init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	else return tree[node] = (init(node * 2, start, (start + end) / 2) *
		init(node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

// update = 범위 안에 있다면 갱신
ll update(int node, int start, int end, int index, int num) {
	if (index < start || index > end) return tree[node];
	if (start == end) return tree[node] = num;
	ll left_tree = update(node * 2, start, (start + end) / 2, index, num);
	ll right_tree = update(node * 2 + 1, (start + end) / 2 + 1, end, index, num);
	return tree[node] = (left_tree * right_tree) % MOD;
}

// query
ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node] % MOD;
	return (query(node * 2, start, (start + end) / 2, left, right) *
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else cout << query(1, 1, n, b, c) << "\n";
	}
}