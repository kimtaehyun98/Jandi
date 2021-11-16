#include <bits/stdc++.h>
using namespace std;

struct tup {
	char c;
	int d;
};

int main() {
	int n, now;
	char dir;
	cin >> n;
	map<int, tup>m;
	for (int i = 0; i < n; i++) {
		tup temp;
		cin >> now >> temp.c >> temp.d;
		m.insert(pair<int, tup>(now, temp));
	}
	cin >> now;
	for (int i = 0; i < n; i++) {
		auto iter = m.find(now);
		tup t = iter->second;
		now += t.c == 'R' ? t.d : (-1) * t.d;
	}
	cout << now << "\n";
}