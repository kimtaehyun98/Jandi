#include <bits/stdc++.h>
using namespace std;

int check[1000002];
int arr[1000002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, ans = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) { 
			if (check[arr[i] + 1] > 0) { // 연결될 수 있다면
				check[arr[i] + 1]--;
				cnt--;
			}
			flag = false;
		}
		if (i == n - 1) break;
		if (arr[i] == arr[i + 1] + 1) { // 감소하고 있다면
			continue;
		}
		else { // 끊김
			if (arr[i] == 1) ans++; // 1에서 끝났다면 정답에 추가
			else { // 끝이 1이 아니다 -> 뒤의 부분들과 연결 가능 -> 저장
				check[arr[i]]++;
				cnt++;
			}
			flag = true;
		}
	}
	ans += cnt + 1;
	cout << ans << "\n";
}