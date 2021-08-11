#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; ll m, s, e;
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		if(s > e) v.push_back(pll(e, s));
	}
	sort(v.begin(), v.end());
	ll ps, pe, ns, ne, ans = 0;
	if (!v.empty()) ps = v[0].first, pe = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		ns = v[i].first, ne = v[i].second;
		if (ps <= ns && ns <= pe) {
			if (ne > pe) pe = ne;
		}
		else {
			ans += pe - ps;
			ps = ns; pe = ne;
		}
	}
	ans += pe - ps;
	ans = (ans * 2) + m;
	cout << ans << "\n";
}