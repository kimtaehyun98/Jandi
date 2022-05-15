#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') str[i] -= 32;
		else str[i] += 32;
	}
	cout << str << "\n";
}