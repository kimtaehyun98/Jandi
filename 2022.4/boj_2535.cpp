#include <bits/stdc++.h>
using namespace std;

struct people {
	int cid, sid, score;
};

bool cmp(people a, people b) {
	return a.score > b.score;
}

int check[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, a, b, c, cnt = 0;
	cin >> n;
	vector<people>v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (check[v[i].cid] < 2) {
			check[v[i].cid]++;
			cnt++;
			cout << v[i].cid << " " << v[i].sid << "\n";
		}
		if (cnt == 3) break;
	}
}