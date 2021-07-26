#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <string, priority_queue<ll, vector<ll>>> psq;


int main() {
	// 어떤 이름을 가진 고릴라가 C1,C2, ... Ck만큼의 가치를 가진 정보 k개 얻음
	// 임의의 시점에 특정 고릴라에게 정보를 몇 개 살것인지를 정할 수 있음
	// 가장 비싼 정보들 구매
	// 한 번 거래한 정보는 파괴
	// 1 -> k개의 정보를 얻었으며 각 가치는 C1 ~ Ck 이다
	// 2 -> b개의 정보를 구입한다 (b개 이하면 가진 모든 정보 구입)
	int q, x, k, b;
	ll ans = 0, c;
	bool check;
	string name;
	map<string, priority_queue<ll, vector<ll>>>m;
	cin >> q;
	while (q--) {
		cin >> x >> name;
		if (x == 1) {
			priority_queue<ll, vector<ll>> temp;
			cin >> k;
			m.find(name) == m.end() ? check = true : check = false;
			for (int i = 0; i < k; i++) {
				cin >> c;
				check ? temp.push(c) : m[name].push(c);
			}
			if (check) m.insert(psq(name, temp));
		}
		else {
			cin >> b;
			while (b--) {
				if (m[name].empty()) break;
				ans += m[name].top();
				m[name].pop();
			}
		}
	}
	cout << ans << "\n";
}