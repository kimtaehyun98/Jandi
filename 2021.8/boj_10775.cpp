#include <bits/stdc++.h>
using namespace std;

int g, p, x, ans = 0;
int parent[100007];
bool check[100007];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int px = find(x), py = find(y);
	x > y ? parent[px] = py : parent[py] = px; // 부모는 항상 최소값을 가지고 있게 됨
}

void init() {
	for (int i = 1; i <= g; i++) parent[i] = i;
	memset(check, false, sizeof(check));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> g >> p;
	init();
	bool stop = false;
	for (int i = 0; i < p; i++) {
		cin >> x;
		if (stop) continue;
		int px = find(x);
		if (px == 0) stop = true;
		else {
			Union(px, px - 1);
			ans += 1;
		}
	}
	cout << ans << "\n";
}