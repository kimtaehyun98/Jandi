#include <bits/stdc++.h>
using namespace std;

struct s {
	int x;
	int t;
	char c;
};

bool cmp(s a, s b) {
	if (a.t != b.t) return a.t < b.t;
	else return a.x < b.x;
}

int main() {
	int n, m, a, b; char cc;
	cin >> n >> m;
	vector<s>v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cc;
		v.push_back(s{ a, b, cc });
	}
	sort(v.begin(), v.end(), cmp);
	string ans = "";
	for (int i = 0; i < v.size(); i++) {
		ans += v[i].c;
	}
	cout << ans << "\n";
}