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
			if (check[arr[i] + 1] > 0) { // ����� �� �ִٸ�
				check[arr[i] + 1]--;
				cnt--;
			}
			flag = false;
		}
		if (i == n - 1) break;
		if (arr[i] == arr[i + 1] + 1) { // �����ϰ� �ִٸ�
			continue;
		}
		else { // ����
			if (arr[i] == 1) ans++; // 1���� �����ٸ� ���信 �߰�
			else { // ���� 1�� �ƴϴ� -> ���� �κе�� ���� ���� -> ����
				check[arr[i]]++;
				cnt++;
			}
			flag = true;
		}
	}
	ans += cnt + 1;
	cout << ans << "\n";
}