#include <bits/stdc++.h>
using namespace std;

int parent[100007];

struct point {
	int x1;
	int x2;
	int y;
	int index;
};

struct cmp {
	bool operator() (point a, point b) {
		if (a.x1 != b.x1) return a.x1 < b.x1;
		else {
			if (a.x2 != b.x2) return a.x2 < b.x2;
			else return a.y < b.y;
		}
	}
};

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int px = find(x), py = find(y);
	x > y ? parent[px] = py : parent[py] = px; // 부모는 항상 최소값을 가지고 있게 됨
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q, x1, x2, y, a, b;
	cin >> n >> q;
	vector<point>tree;
	for (int i = 1; i <= n; i++) {
		cin >> x1 >> x2 >> y;
		tree.push_back(point{ x1, x2, y, i });
	}
	sort(tree.begin(), tree.end(), cmp());
	// 점프 가능하면 union 시키기
	// = 현재 통나무의 끝점 >= 다음 통나무의 시작점 = Union
	for (int i = 1; i <= n; i++) parent[i] = i;
	point prev = tree[0];
	for (int i = 1; i < n; i++) {
		if (prev.x2 >= tree[i].x1) {
			Union(prev.index, tree[i].index);
			prev.x2 = max(prev.x2, tree[i].x2);
		}
		else {
			prev = tree[i];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (find(a) == find(b)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}