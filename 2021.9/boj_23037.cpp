#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll ans = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) ans += pow(str[i] - '0', 5);
	cout << ans << "\n";
}