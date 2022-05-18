#include <bits/stdc++.h>
using namespace std;

char ans[3][3];
vector<string>v;
bool allStop = false;
bool vCheck[6];

bool allCheck() {
	vector<string>temp;
	for (int a = 0; a < 3; a++) {
		string x = "", y = "";
		for (int b = 0; b < 3; b++) {
			x += ans[a][b];
			y += ans[b][a];
		}
		temp.push_back(x);
		temp.push_back(y);
	}
	bool check[6];
	memset(check, false, sizeof(check));
	for (int i = 0; i < 6; i++) {
		bool stop = false;
		for (int j = 0; j < 6; j++) {
			if (check[j]) continue;
			if (temp[j] == v[i]) {
				check[j] = true;
				stop = true;
				break;
			}
		}
		if (!stop) return false;
	}
	return true;
}

void bt(int cnt) {
	if (cnt == 3) {
		if (allCheck()) {
			allStop = true;
		}
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (vCheck[i]) continue;
		string temp = v[i];
		for (int k = 0; k < 3; k++) {
			ans[cnt][k] = temp[k];
		}
		vCheck[i] = true;
		bt(cnt + 1);
		vCheck[i] = false;
		if (allStop) return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	for (int i = 0; i < 6; i++) {
		cin >> str;
		v.push_back(str);
	}
	bt(0);
	if (allStop) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	else cout << 0 << "\n";
}