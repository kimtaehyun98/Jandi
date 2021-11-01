#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int l, r, cnt = 0; bool check = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '@') cnt++;
		if (str[i] == ')') {
			l = cnt;
			cnt = 0;
		}
	}
	r = cnt;
	cout << l << " " << r << "\n";
}