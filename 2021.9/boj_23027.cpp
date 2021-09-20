#include <bits/stdc++.h>
using namespace std;
int arr[3]; char temp;

bool check(char c) {
	if ('B' == c || c == 'C' || c == 'D' || c == 'F') return true;
	return false;
}

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) if ('A' <= str[i] && str[i] <= 'C') arr[str[i] - 'A']++;
	for (int i = 0; i < str.size(); i++) {
		if (arr[0] != 0) { if (check(str[i])) str[i] = 'A'; }
		else if (arr[1] != 0) { if (check(str[i])) str[i] = 'B'; }
		else if (arr[2] != 0) { if (check(str[i])) str[i] = 'C'; }
		else str[i] = 'A';
	}
	cout << str << "\n";
}