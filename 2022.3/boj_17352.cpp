#include <bits/stdc++.h>
using namespace std;

int root[300003];

int Find(int x) {
	if (root[x] == x) return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x != y) root[y] = x;
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		root[i] = i;
	}
}

int main() {
	int n, a, b;
	cin >> n;
	init(n);
	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	int prev = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) prev = Find(i);
		else {
			int cmp = Find(i);
			if (cmp != prev) {
				cout << cmp << " " << prev << "\n";
				break;
			}
		}
	}
}