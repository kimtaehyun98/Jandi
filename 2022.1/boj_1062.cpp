#include <bits/stdc++.h>
using namespace std;

char alpha[] = { 'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z' };
int n, k, ans;
bool ch[30];
vector<string>v;
bool check[30];

void bt(int cnt, int start) {
	if (cnt == k) {
		int cmp = 0;
		for (int i = 0; i < v.size(); i++) {
			bool flag = true;
			for (int k = 0; k < v[i].size(); k++) {
				if (ch[v[i][k] - 'a'] == false) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cmp++;
			}
		}
		ans = max(ans, cmp);
	}
	else {
		for (int i = start; i < 21; i++) {
			if (check[i] == false) {
				ch[alpha[i] - 'a'] = true;
				check[i] = true;
				bt(cnt + 1, i + 1);
				check[i] = false;
				ch[alpha[i] - 'a'] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str;
		string temp = "";
		for (int s = 0; s < str.size(); s++) {
			char c = str[s];
			if (c != 'a' && c != 'c' && c != 'i' && c != 'n' && c != 't') {
				temp += c;
			}
		}
		v.push_back(temp);
	}
	if (k < 5) {
		cout << 0 << "\n";
	}
	else {
		k -= 5;
		memset(check, false, sizeof(check));
		memset(ch, false, sizeof(ch));
		bt(0, 0);
		cout << ans << "\n";
	}
}