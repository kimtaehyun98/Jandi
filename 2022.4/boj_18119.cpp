#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

string str[10001];
int stb[10001];
bool check[10001];

int strToBits(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret = (ret | (1 << (s[i] - 'a')));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, a, cmp = (1 << 27) - 1; char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		stb[i] = strToBits(str[i]);
	}
	memset(check, true, sizeof(check));
	int ans = n;
	for (int i = 0; i < m; i++) {
		cin >> a >> c;
		if (a == 1) { // x를 잊는다
			int temp = ((1 << 27) - 1) ^ (1 << (c - 'a'));
			cmp = cmp & temp;
			for (int k = 0; k < n; k++) {
				if (check[k]) { // 기억하고 있는 단어 중
					if ((stb[k] & cmp) != stb[k]) {
						ans--;
						check[k] = false;
					}
				}
			}
		}
		else { // x를 기억해낸다
			int temp = 1 << (c - 'a');
			cmp = cmp | temp;
			for (int k = 0; k < n; k++) {
				if (!check[k]) { // 잊은 단어 중
					if ((stb[k] & cmp) == stb[k]) {
						ans++;
						check[k] = true;
					}
				}
			}
		}
		cout << ans << "\n";
	}
}