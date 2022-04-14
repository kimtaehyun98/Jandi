#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		str[i] -= 3;
		if (str[i] < 'A') str[i] = str[i] - 'A' + 'Z' + 1;
	}
	cout << str << "\n";
}