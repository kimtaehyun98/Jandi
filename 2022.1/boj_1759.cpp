#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> arr;
vector<char> temp;
vector<string>ans;

bool check(char s) {
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
	else return false;
}

void bt(int start, int cnt) {
	if (cnt == l) {
		string s = "";
		int mo = 0, ja = 0;
		for (int i = 0; i < temp.size(); i++) {
			s += temp[i];
			if (check(temp[i])) mo++;
			else ja++;
		}
		if (mo >= 1 && ja >= 2) ans.push_back(s);
		return;
	}
	for (int i = start; i < c; i++) {
		temp.push_back(arr[i]);
		bt(i + 1, cnt + 1);
		temp.pop_back();
	}
}

int main() {
	cin >> l >> c;
	char s;
	for (int i = 0; i < c; i++) {
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	bt(0, 0);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}