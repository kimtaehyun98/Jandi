#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, t, start = 0;
	string str;
	cin >> n >> k;
	// n�ڸ� ���� �� ���� k���� ������ ���� �� �ִ� ���� ū �� ���ض�
	// �� ���ڸ��� �ڽ��� ���� �� �ִ� ���� �� �ִ밪�̿��� ��
	cin >> str;
	deque<char>dq; t = k;
	dq.push_back(str[0]);
	for (int i = 1; i < str.size(); i++) {
		while (!dq.empty() && dq.back() < str[i] && k > 0) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	for (int i = 0; i < n - t; i++)cout << dq[i];
}