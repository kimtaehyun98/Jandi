#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string oper, temp;
		ll l, r, cmp, ans;
		cin >> l >> oper >> r >> temp >> cmp;
		if (oper == "+") ans = l + r;
		if (oper == "-") ans = l - r;
		if (oper == "*") ans = l * r;
		if (oper == "/") ans = l / r;
		if (cmp == ans) cout << "correct" << "\n";
		else cout << "wrong answer" << "\n";
	}
}