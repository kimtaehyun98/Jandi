#include <bits/stdc++.h>
using namespace std;

int arr[9];
int temp = 0;
bool check[9];
bool stop = false;

void bt(int cnt) {
	if (stop) return;
	if (cnt == 7) {
		if (temp == 100) {
			for (int i = 0; i < 9; i++) {
				if (check[i]) cout << arr[i] << "\n";
			}
			stop = true;
			return;
		}
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (check[i] == false) {
				check[i] = true;
				temp += arr[i];
				bt(cnt + 1);
				temp -= arr[i];
				check[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) cin >> arr[i];
	memset(check, false, sizeof(check));
	bt(0);
}