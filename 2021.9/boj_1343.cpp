#include <bits/stdc++.h>
using namespace std;

void print(int x) {
	for (int i = 0; i < x / 4; i++) cout << "AAAA";
	if (x % 4 != 0) cout << "BB";
}

int main() {
	string str;
	cin >> str;
	int cnt = 0; bool stop = false;
	vector<int>v;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'X') cnt++;
		else {
			if (cnt % 2 != 0) {
				stop = true;
				break;
			}
			v.push_back(cnt);
			cnt = 0;
		}
	}
	if (stop || cnt % 2 != 0) cout << -1 << "\n";
	else {
		v.push_back(cnt);
		for (int i = 0; i < v.size(); i++) {
			if (i != 0)cout << '.';
			print(v[i]);
		}
	}
}